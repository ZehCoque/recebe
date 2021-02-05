#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "RecebeComando.h"
#include <QtQuick>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QObject *rootObj = engine.rootObjects().first();
    QObject *item = rootObj->findChild<QObject*>("recebeButtonMouseArea");

    RecebeComando myClass;
    bool success= QObject::connect(item, SIGNAL(qmlSignal(QString)),
                     &myClass, SLOT(cppSlot(QString)));
    Q_ASSERT(success);
    return app.exec();
}
