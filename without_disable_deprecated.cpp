#include <QDebug>
#include <QLocale>

void without_disable_deprecated() {
    qInfo() << QLocale(QString("en"));
}
