#include "filetransfermanager.h"
#include "notificationmanager.h"


FileTransferManager::FileTransferManager(NotificationManager *notificationMgr,
                                         QObject *parent)
    : QObject{parent},
    m_notificationManager(notificationMgr)
{}

void FileTransferManager::defineTransferInfo(quint32 transferId, const QString filePath){
    QFileInfo fileInfo(filePath);
    OutgoingFileTransfer transfer;
    transfer.fileName = fileInfo.fileName();
    transfer.fileSize = fileInfo.size();
    transfer.filePath = filePath;

    NotificationInfo fileNotification;
    fileNotification.eventType = EventType::FileTransferRequestSent;
    fileNotification.showAbortButton = false;
    fileNotification.showAcceptButton = false;
    fileNotification.showRejectButton = false;
    fileNotification.showCancelButton = false;
    fileNotification.showProgressBar = false;
    fileNotification.description = tr("Запрос на отправку файла %1 отправлен собеседнику.")
                                       .arg(transfer.fileName);
    fileNotification.data = transferId;
    transfer.notificationId = m_notificationManager->displayNotification(fileNotification);
    m_outgoingTransfers.insert(transferId, transfer);
}

void FileTransferManager::processFileTransferRequest(const FileInfoHeader &fileInfo, const QString &fileName,
                                const QHostAddress &senderAddress, quint16 senderPort){
    IncomingFileTransfer transfer;
    transfer.fileSize = fileInfo.fileSize;
    transfer.fileName = fileName;
    transfer.senderAddress = senderAddress;
    transfer.senderPort = senderPort;

    NotificationInfo fileNotification;
    fileNotification.eventType = EventType::FileTransferRequestRecieved;
    fileNotification.showAbortButton = false;
    fileNotification.showAcceptButton = true;
    fileNotification.showRejectButton = true;
    fileNotification.showCancelButton = false;
    fileNotification.showProgressBar = false;
    fileNotification.description = tr("Собеседник %1 отправил запрос на передачу файла:\nНазвание: %2 Размер: %3")
                                       .arg(senderAddress.toString(), fileName, QString::number(fileInfo.fileSize));
    fileNotification.data = fileInfo.fileTransferMessageId;

    transfer.notificationId = m_notificationManager->displayNotification(fileNotification);
    m_incomingTransfers.insert(fileInfo.fileTransferMessageId, transfer);
}

void FileTransferManager::handleFileTransferAnswer(quint32 transferId, bool accepted){
    IncomingFileTransfer transfer = m_incomingTransfers.value(transferId);

    if (!accepted){
        m_notificationManager->removeNotification(transfer.notificationId);
        m_incomingTransfers.remove(transferId);
    }
    else{
        NotificationInfo changedNotification = m_notificationManager->getInfo(transfer.notificationId);
        changedNotification.showAcceptButton = false;
        changedNotification.showRejectButton = false;
        changedNotification.showProgressBar = true;
        changedNotification.showAbortButton = true;
        changedNotification.description = tr("Получение файла от %1\nНазвание: %2 Размер: %3")
                                              .arg(transfer.senderAddress.toString(), transfer.fileName, QString::number(transfer.fileSize));
        changedNotification.eventType = EventType::FileDownloading;
        m_notificationManager->changeNotification(transfer.notificationId, changedNotification);
    }
}

void FileTransferManager::processFileTransferPermission(quint32 transferId, bool permission){
    OutgoingFileTransfer transfer = m_outgoingTransfers.value(transferId);
    NotificationInfo changedNotification = m_notificationManager->getInfo(transfer.notificationId);
    if (!permission){
        changedNotification.showCancelButton = true;
        changedNotification.description = tr("Собеседник %1 отклонил запрос на передачу файла\nНазвание: %2 Размер: %3")
                    .arg(transfer.targetAddress.toString(), transfer.fileName, QString::number(transfer.fileSize));
        changedNotification.eventType = EventType::FileTransferDeclined;
        m_notificationManager->changeNotification(transfer.notificationId, changedNotification);
    }
    else{
        changedNotification.showAbortButton = true;
        changedNotification.showProgressBar = true;
        changedNotification.description = tr("Начата передача файла собеседнику %1\nНазвание: %2 Размер: %3")
                    .arg(transfer.targetAddress.toString(), transfer.fileName, QString::number(transfer.fileSize));
        changedNotification.eventType = EventType::FileTransferStarted;
        m_notificationManager->changeNotification(transfer.notificationId, changedNotification);
        sendFile(transferId);
    }
}

void FileTransferManager::sendFile(quint32 transferId){
    OutgoingFileTransfer transfer = m_outgoingTransfers.value(transferId);
    QString filePath = transfer.filePath;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() <<"Error: Не удалось открыть файл по пути:" + filePath;
        return;
    }
    // не сохраняем id т.к. сообщение запроса передачи и сообщение самой передачи имели один id
    emit fileReadyToUpload(transferId, file);
    file.close();
}

void FileTransferManager::processFileDownloaded(quint32 transferId, const QByteArray payload){
    QString downloadsDir = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    IncomingFileTransfer transfer = m_incomingTransfers.value(transferId);
    QString filePath = downloadsDir + "/" + transfer.fileName;

    QFile file(filePath);
    NotificationInfo changedNotification = m_notificationManager->getInfo(transfer.notificationId);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(payload);
        file.close();
        changedNotification.description = tr("Полученный от %1 файл успешно сохранён по пути:\n%2")
                                              .arg(transfer.senderAddress.toString(), filePath);
        changedNotification.eventType = EventType::FileInstalled;
    } else {
        changedNotification.description = tr("Полученный от %1 файл не удалось сохранить по пути:\n%2")
                          .arg(transfer.senderAddress.toString(), downloadsDir);
        changedNotification.eventType = EventType::FileFailedToInstall;
    }
    // оповещение о завершении скачки
    changedNotification.showAbortButton = false;
    changedNotification.showCancelButton = true;
    changedNotification.showProgressBar = false;
    m_notificationManager->changeNotification(transfer.notificationId, changedNotification);
    m_incomingTransfers.remove(transferId); // Сбрасываем состояние
}

void FileTransferManager::updateSentFileProgress(quint32 transferId, quint8 progress){
    OutgoingFileTransfer transfer = m_outgoingTransfers.value(transferId);
    m_notificationManager->updateNotificationProgress(transfer.notificationId, progress);
}

void FileTransferManager::updateReceivedFileProgress(quint32 transferId, quint8 progress){
    IncomingFileTransfer transfer = m_incomingTransfers.value(transferId);
    m_notificationManager->updateNotificationProgress(transfer.notificationId, progress);
}

void FileTransferManager::processFileAck(quint32 transferId){
    OutgoingFileTransfer transfer = m_outgoingTransfers.value(transferId);
    NotificationInfo changedNotification = m_notificationManager->getInfo(transfer.notificationId);
    changedNotification.showProgressBar = false;
    changedNotification.showAbortButton = false;
    changedNotification.showCancelButton = true;
    changedNotification.description = tr("Собеседник %1 успешно получил файл.\nНазвание файла: %2")
                                          .arg(transfer.targetAddress.toString(), transfer.fileName);
    changedNotification.eventType = EventType::FileDelivered;
    m_notificationManager->changeNotification(transfer.notificationId, changedNotification);
    m_outgoingTransfers.remove(transferId);
}
