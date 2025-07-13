#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include "Structs.h"

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

public slots:
    void saveMessage(const ChatMessage &message);
    bool connectToDatabase(const QString dbName, const QString dbUser, const QString dbPassword);

private:
    void createMessagesTable();
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
