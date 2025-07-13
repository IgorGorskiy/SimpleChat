#ifndef STRUCTS_H
#define STRUCTS_H

#include <QtGlobal>
#include <QHostAddress>
#include <QDateTime>
#include <QByteArray>
#include <QString>
#include <QMetaType> // Для Q_DECLARE_METATYPE
#include "Constants.h"
#include "qtimer.h"

// Убедитесь, что структуры будут упакованы без выравнивания для передачи по сети

// --- Протокольные структуры ---
enum MessageType : quint8 { // Использовать quint8 для явного размера
    TextMessage = 0,
    File = 1,
    FileTransferRequest = 2,
    FileTransferPermission = 3,
    Ack = 4,
    Ping = 5,
    ReQuery = 6,
    // ... можно добавить другие типы, например, VoiceCall, VoiceCallAnswer, etc.
};
#pragma pack(push, 1)
struct MessageHeader {
    quint32 messageId;       // Unique message identifier (для всего сообщения, а не только пакета)
    quint16 totalPackets;    // Total packets in this message
    quint16 packetNumber;    // Current packet number (1-based)
    quint32 payloadSize;     // Size of this packet's payload
    MessageType messageType; // Тип сообщения (использовать enum)
    quint16 packetInterval;  // Интервал между отправкой пакетов (для больших сообщений)
};

struct FileInfoHeader {
    quint16 filenameLength;
    qint64 fileSize; // Используем qint64 для больших файлов
    quint32 fileTransferMessageId; // ID связанного сообщения о передаче файла
    bool permissionGiven; // Используется в FileTransferPermission
    // Добавим Q_DECLARE_METATYPE ниже для передачи в QVariant
};

// --- Вспомогательные структуры для работы внутри приложения ---


struct ConnectionSettings{
    quint16 localPort = 0;
    quint16 remotePort = 0;
    QHostAddress remoteAddress = QHostAddress::LocalHost; // по умолчанию - собственный адрес
    QHostAddress localAddress = QHostAddress::LocalHost;
    quint8 maxThreads;
};

struct ComposerSettings{
    quint32 maxPacketSize;
    quint16 packetInterval;
};

// Сообщение для отображения в UI
struct ChatMessage {
    quint32 id;
    QString text;
    QString sender;
    QDateTime timestamp;
    bool isOutgoing;
    enum Status { Sending, Sent, Delivered, Error, CommandOutput, None } status;
};

// Информация о неполном входящем сообщении
struct IncompleteMessage {
    quint32 messageId;
    quint16 receivedPacketsCount = 0;
    quint16 totalPackets = 0;
    QMap<quint16, QByteArray> packets; // Хранение полученных пакетов
    QTimer *assemblyTimer;
    quint16 packetInterval;
    QVector<quint16> missingPacketsIds; // Для ReQuery
    QHostAddress senderAddress;
    quint16 senderPort;
    MessageType messageType; // Тип сообщения
};

// Информация для уведомлений

enum EventType {
    FileTransferStarted,          // Передача файла началась
    FileTransferDeclined,         // Передача файла отклонена
    FileTransferRequestSent,
    FileTransferRequestDelivered,
    FileTransferRequestRecieved,  // Запрос на передачу файла
    FileDownloading,              // Загрузка файла (для обновления прогресса)
    FileInstalled,                // Файл успешно сохранен
    FileFailedToInstall,
    FileDelivered,                // Файл успешно доставлен (отправителем)
    VoiceCallIncoming,            // Входящий голосовой вызов
    VoiceCallEnded,               // Звонок завершен
    MessageError,                 // Ошибка сообщения
    // ... другие типы событий
};

struct NotificationInfo {
    quint32 notificationId; // Уникальный ID для этого уведомления (генерируется NotificationManager)
    EventType eventType; // Тип события для NotificationWidget
    QString senderName;
    QString description;
    bool showAcceptButton = true;
    bool showRejectButton = true;
    bool showAbortButton = true;
    bool showCancelButton = true;
    bool showProgressBar = false;
    QVariant data; // Дополнительные данные, специфичные для события (например, transferId)
};

namespace AppConstants{
const quint32 MAX_MESSAGE_PAYLOAD_SIZE = MAX_PACKET_SIZE - sizeof(MessageHeader);
}

// Информация о запросе на передачу файла
struct FileTransferRequestInfo {
    quint32 transferId; // messageId, связанный с запросом FileTransferRequest
    QString fileName;
    qint64 fileSize;
    QHostAddress senderAddress;
    quint16 senderPort;
};

// Информация о прогрессе передачи файла
struct FileProgressInfo {
    quint32 transferId;
    quint64 bytesTransferred;
    quint64 totalBytes;
    bool isSending; // true для отправки, false для получения
    // Добавим Q_DECLARE_METATYPE ниже для передачи в QVariant
};


#pragma pack(pop) // Отключение упаковки

// --- Объявления Q_DECLARE_METATYPE для всех структур, используемых в сигналах/слотах ---
// Это необходимо, если вы хотите передавать пользовательские структуры через QVariant
// или использовать их в прямых соединениях сигналов/слотов через queued-соединения.
Q_DECLARE_METATYPE(ChatMessage)
Q_DECLARE_METATYPE(IncompleteMessage)
Q_DECLARE_METATYPE(NotificationInfo)
Q_DECLARE_METATYPE(FileTransferRequestInfo)
Q_DECLARE_METATYPE(FileProgressInfo)
Q_DECLARE_METATYPE(MessageHeader)
Q_DECLARE_METATYPE(FileInfoHeader)

#endif // STRUCTS_H
