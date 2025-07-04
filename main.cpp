#include "ChatWindow.h"
#include <QApplication>
#include "Structs.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ConnectionSettings con;
    con.localAddress = QHostAddress::LocalHost;
    con.remoteAddress = QHostAddress::LocalHost;
    con.localPort = 12345;
    con.remotePort = 12346;
    ChatWindow w(con, nullptr);
    con.localPort = 12346;
    con.remotePort = 12345;
    ChatWindow z(con, nullptr);
    w.show();
    z.show();
    return a.exec();
}
