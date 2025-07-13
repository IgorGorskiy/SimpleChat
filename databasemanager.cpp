#include "databasemanager.h"
#include <QDebug>
#include <QStandardPaths>

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject(parent)
{

}

DatabaseManager::~DatabaseManager()
{
    if (m_db.isOpen()) {
        m_db.close();
        m_db = QSqlDatabase();
        QSqlDatabase::removeDatabase("qt_sql_default_connection");
    }
}

bool DatabaseManager::connectToDatabase(const QString dbName, const QString dbUser, const QString dbPassword)
{
    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName("localhost");
    m_db.setDatabaseName(dbName);
    m_db.setUserName(dbUser);
    m_db.setPassword(dbPassword);
    m_db.setPort(5432);

    if (!m_db.open()) {
        qDebug() << "Error: Failed to connect to database:" << m_db.lastError().text();
        return false;
    }
    qDebug() << "Connected to PostgreSQL database!";
    createMessagesTable();
    return true;
}

void DatabaseManager::createMessagesTable()
{
    if (!m_db.isOpen()) {
        qDebug() << "Database not open. Cannot create table.";
        return;
    }

    QSqlQuery query(m_db);
    QString createQuery = "CREATE TABLE IF NOT EXISTS messages ("
                          "id SERIAL PRIMARY KEY, "
                          "message_id BIGINT UNIQUE, " // Уникальный ID сообщения
                          "text TEXT, "
                          "sender TEXT, "
                          "timestamp TIMESTAMP, "
                          "is_outgoing BOOLEAN, "
                          "status INTEGER"
                          ");";
    if (!query.exec(createQuery)) {
        qDebug() << "Error creating messages table:" << query.lastError().text();
    } else {
        qDebug() << "Messages table created or already exists.";
    }
}

void DatabaseManager::saveMessage(const ChatMessage &message)
{
    if (!m_db.isOpen()) {
        qDebug() << "Database not open. Cannot save message.";
        return;
    }

    QSqlQuery query(m_db);
    // Используем подготовленное выражение для безопасности
    query.prepare("INSERT INTO messages (message_id, text, sender, timestamp, is_outgoing, status) "
                  "VALUES (:message_id, :text, :sender, :timestamp, :is_outgoing, :status)");

    // Привязываем значения
    query.bindValue(":message_id", QVariant::fromValue(message.id)); // Убедитесь, что `message.id` - это quint32
    query.bindValue(":text", message.text);
    query.bindValue(":sender", message.sender);
    query.bindValue(":timestamp", message.timestamp);
    query.bindValue(":is_outgoing", message.isOutgoing);
    query.bindValue(":status", message.status);

    if (!query.exec()) {
        qDebug() << "Error saving message:" << query.lastError().text();
    } else {
        qDebug() << "Message saved to DB:" << message.id;
    }
}
