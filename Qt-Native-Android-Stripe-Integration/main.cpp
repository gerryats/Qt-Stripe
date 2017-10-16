#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <android/androidstripetoken.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    AndroidStripeToken * stripetoken =  new AndroidStripeToken();
    stripetoken->FetchToken();

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
