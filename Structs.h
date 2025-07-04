#ifndef STRUCTS_H
#define STRUCTS_H
#include "qdatetime.h"
#include "qglobal.h"
#include "qhostaddress.h"

enum MessageType {
    TextMessage,
    FileChunk,
    FileTransferRequest,
    FileTransferPermission,
    Ack,
    Ping,
    PingAnswer
};
enum EventType  {
    FileTransferStarted,
    FileTransferDeclined,
    FileTransferRequestRecieved,
    FileDownloading,
    FileInstalled,
    FileDelivered,
    VoiceCall
};
#pragma pack(push, 1)
struct FileInfoHeader {
    quint16 filenameLength;
    qint32 fileSize;
    quint32 fileTransferMessageId;
    bool permissionGiven;
};

struct MessageHeader {
    quint32 messageId;       // Unique message identifier
    quint16 totalPackets;    // Total packets in message
    quint16 packetNumber;    // Current packet number (1-based)
    quint32 payloadSize;     // Size of this packet's payload
    quint8 messageType;
};
struct MessagePacket {
    quint16 packetNumber;
    quint16 totalPackets;
    QByteArray payload;
};

struct IncompleteMessage {
    quint32 messageId;
    quint16 receivedPackets = 0;
    quint16 totalPackets = 0;
    QMap<quint16, QByteArray> packets;
    QDateTime lastPacketTime;
};
struct ConnectionSettings{
    quint16 localPort = 0;
    quint16 remotePort = 0;
    QHostAddress remoteAddress = QHostAddress::LocalHost; // по умолчанию - собственный адрес
    QHostAddress localAddress = QHostAddress::LocalHost;
    bool connectionEstablished;
};

struct AckPacket{
    MessageHeader originalHeader;
    quint64 checkSum; // не реализовано
};

struct FreePorts{

};

#pragma pack(pop)

#endif // STRUCTS_H
