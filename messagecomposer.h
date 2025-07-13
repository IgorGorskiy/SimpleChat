#ifndef MESSAGECOMPOSER_H
#define MESSAGECOMPOSER_H

#include <QObject>
#include <QVector>
#include <QByteArray>
#include <QHostAddress>
#include "qfileinfo.h"
#include "Structs.h"

class MessageComposer : public QObject
{
    Q_OBJECT

public:
    explicit MessageComposer(QObject *parent = nullptr);

    // Методы для создания пакетов разных типов
    // Возвращают вектор дейтаграмм, готовых к отправке
    void createTextDatagrams(const QString text);
    void createFileTransferRequestDatagrams(const QString filePath);
    void createFileTransferPermissionDatagrams(quint32 transferId, bool permission);
    void createFileDatagrams(quint32 transferId, QFile &file);
    void createAckDatagrams(MessageHeader originalHeader);
    void createPingDatagrams();
    void createReQueryDatagrams(quint32 originalMessageId, const QVector<quint16> missingPacketNumbers);

    ComposerSettings getComposerSettings();

public slots:
    void setComposerSettings(ComposerSettings settings);

signals:
    // Сигнал, сообщающий о готовности дейтаграмм для отправки NetworkManager
    void datagramsReadyForSending(quint32 messageId, const QVector<QByteArray> datagrams,
                                  bool ackRequired);
    void textMessageComposed(quint32 messageId, const QString text);
    void transferRequestReady(quint32 transferId, QString filePath);

private:
    // Вспомогательный метод для разделения полезной нагрузки на пакеты
    QVector<QByteArray> splitPayloadIntoPackets(quint32 messageId, MessageType type,
                                                const QByteArray &fullPayload, quint16 packetInterval);

    quint32 m_currentMessageId = 1; // Для генерации уникальных ID; не должен быть равен 0
    ComposerSettings m_currentSettings;
};

#endif // MESSAGECOMPOSER_H
