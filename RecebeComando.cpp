#include "RecebeComando.h"
#include <QtDBus/QDBusConnection>
#include <QtDBus/QtDBus>
#include <QtDebug>

RecebeComando::RecebeComando(QObject *parent) : QObject(parent)
{

}

//realiza a conexao com o DBus, nome e slot adequados
void RecebeComando::connectToBus(const QString &topic){
    m_topic = topic;

    //conexao dessa classe - slot messageSlot - com o signal DBus
    bool connectionSuccess = QDBusConnection::sessionBus().connect("","",SERVICE_NAME,topic,this,SLOT(messageSlot(QString)));
    Q_ASSERT(connectionSuccess); //testa se a conexao foi feita com sucesso
}

//recebe o valor msg do signal DBus com o nome adequado
void RecebeComando::messageSlot(const QString &msg){
    m_msg = msg;

    //disconecta a classe do DBus depois que a mensagem foi recebida
    bool disconnectionSuccess = QDBusConnection::sessionBus().disconnect("","",SERVICE_NAME,m_topic,this,SLOT(messageSlot(QString)));
    Q_ASSERT(disconnectionSuccess);
    emit messageChanged();
}

//retorna o valor da variavel m_msg salvo na classe
QString RecebeComando::msg(){
    return m_msg;
}
