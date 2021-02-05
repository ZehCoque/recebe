#ifndef RECEBECOMANDO_H
#define RECEBECOMANDO_H

#include <QObject>
#include <QString>
#include <qqml.h>


#define SERVICE_NAME            "otmis.Desafio"

class RecebeComando : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString msg READ msg) //receber o valor retornado pela funcao msg
    Q_PROPERTY(QString topic WRITE connectToBus) //atribuir o valor de topic a funcao connectToBus
    QML_ELEMENT

public:
    explicit RecebeComando(QObject *parent = nullptr);

    QString msg(); //retorna o valor da variavel m_msg

    void connectToBus(const QString &topic); //realiza a conexao com o DBus

signals:
    void messageChanged(); //sinal emitido toda vez que um sinal DBus e recebido

public slots:
    void messageSlot(const QString &msg);

private:
    QString m_msg;
    QString m_topic;

signals:

};

#endif // RECEBECOMANDO_H
