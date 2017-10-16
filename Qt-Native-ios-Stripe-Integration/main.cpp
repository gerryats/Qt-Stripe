#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ios/stripetoken.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    StripeToken *tok = new StripeToken();
    QString str = tok->GetToken();
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
