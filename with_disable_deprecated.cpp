#include <QDebug>
#include <QLocale>

void with_disable_deprecated() {
    qInfo() << QLocale(QString("en"));
}
