#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "qchar.h"
#include "qobject.h"
#include <QtGlobal> // Для quint16, quint32 и т.д.

namespace AppConstants {
const quint16 DEFAULT_LOCAL_PORT = 12345;
const quint16 DEFAULT_REMOTE_PORT = 12346;
const QString DEFAULT_REMOTE_ADDRESS = "127.0.0.1";

const quint32 MAX_PACKET_SIZE = 512; // Максимальный размер полезной нагрузки UDP пакета

const int ACK_TIMEOUT_MS = 5000;      // Таймаут ожидания ACK для сообщения
const int REQUERY_INTERVAL_MS = 2000; // Интервал для повторных запросов пакетов
const int MESSAGE_RESEND_COUNT = 3;   // Количество попыток повторной отправки сообщения/пакета

const int UI_UPDATE_INTERVAL_MS = 100; // Интервал обновления UI (например, прогресс-баров)

}

#endif // CONSTANTS_H
