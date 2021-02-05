#ifndef RECEBECOMANDO_H
#define RECEBECOMANDO_H

#include <QObject>

#define SERVICE_NAME            "otmis.Desafio"

class RecebeComando : public QObject
{
    Q_OBJECT

public:
    explicit RecebeComando(QObject *parent = nullptr);

public slots:
    Q_SCRIPTABLE void cppSlot(const QString msg);


signals:

};

#endif // RECEBECOMANDO_H
