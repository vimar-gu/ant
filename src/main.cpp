#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <sys/time.h>
#include <iostream>
#include "field.h"
#include "city.h"
using namespace std;

void qmlRegister(){
    qmlRegisterType<Field>("Client.Component", 1, 0, "Field");
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegister();
    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:src/qml/main.qml")));

    struct timeval time_out;
    gettimeofday(&time_out, NULL);
    if (time_out.tv_sec) {
        qDebug() << "time" << endl;
        City::instance()->fresh();
    }

    return app.exec();
}
