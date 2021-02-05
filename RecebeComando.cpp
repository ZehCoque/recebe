#include "RecebeComando.h"
#include <QtDBus/QDBusConnection>
#include <QtDBus/QtDBus>
#include <QtDebug>

RecebeComando::RecebeComando(QObject *parent) : QObject(parent)
{
    QDBusConnection::sessionBus().registerObject("/", this, QDBusConnection::ExportAllSlots);
}

//QString RecebeComando::msgSlot(const QString &msg){
//    return "msg recebida";
//}

void RecebeComando::cppSlot(const QString msg) {
    qDebug() << "Called the C++ slot with message: " << msg;
}
