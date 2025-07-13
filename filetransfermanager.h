#ifndef FILETRANSFERMANAGER_H
#define FILETRANSFERMANAGER_H

#include <QObject>
#include <QFile>
#include <QHostAddress>
#include <QMap>
#include "qfileinfo.h"
#include <QStandardPaths>
#include "Structs.h"

// Forward declarations

class NotificationManager;

class FileTransferManager : public QObject
{
    Q_OBJECT

public:
    explicit FileTransferManager(NotificationManager *notificationMgr,
                                 QObject *parent = nullptr);

public slots:
    // вызывается при отправке запроса разрешения на отправку файла
    void defineTransferInfo(quint32 transferId, const QString filePath);

    // Слоты для обработки входящих сообщений от ProtocolHandler
    void processFileTransferRequest(const FileInfoHeader &fileInfo, const QString &fileName,
                                    const QHostAddress &senderAddress, quint16 senderPort);
    void processFileTransferPermission(quint32 transferId, bool permission);

    // Слоты для обработки ответов от NotificationManager
    void handleFileTransferAnswer(quint32 transferId, bool accepted);

    void updateSentFileProgress(quint32 transferId, quint8 progress);
    void updateReceivedFileProgress(quint32 transferId, quint8 progress);

    void processFileDownloaded(quint32 transferId, const QByteArray payload);
    void processFileAck(quint32 transferId);
signals:
    void fileReadyToUpload(quint32 transferId, QFile &file);

private:
    NotificationManager *m_notificationManager;

    // Для исходящих передач (messageId -> (filePath, file, currentChunk, totalChunks, targetAddress, targetPort))
    struct OutgoingFileTransfer {
        quint32 dataMessageId = 0;
        quint32 notificationId;
        QString filePath;
        QString fileName;
        qint64 bytesSent;
        qint64 fileSize;
        QHostAddress targetAddress;
        quint16 targetPort;
    };
    // ключ - id сообщения запроса разрешения на передачу
    QMap<quint32, OutgoingFileTransfer> m_outgoingTransfers;

    // Для входящих передач (messageId -> (fileName, file, receivedBytes, totalBytes))
    struct IncomingFileTransfer {
        quint32 dataMessageId = 0;
        quint32 notificationId;
        QString fileName;
        qint64 bytesReceived;
        qint64 fileSize;
        QHostAddress senderAddress;
        quint16 senderPort;
    };
    // ключ - id сообщения запроса разрешения на передачу
    QMap<quint32, IncomingFileTransfer> m_incomingTransfers;

    void sendFile(quint32 transferId);
};

#endif // FILETRANSFERMANAGER_H
