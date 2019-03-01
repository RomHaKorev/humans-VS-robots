#include <QtQuickTest/quicktest.h>

#include <model/world.h>
#include <elements/hero.h>
#include <elements/bullet.h>
#include <elements/grounditem.h>

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include <QDebug>

//QUICK_TEST_MAIN(example)
int main(int argc, char **argv)
{
    QDir d(":/");
    for (QString filename: d.entryList())
    {
        qDebug() << filename;
    }
    qmlRegisterType<Hero>("app.components", 1, 0, "Hero");
    qmlRegisterType<GroundItem>("app.components", 1, 0, "Ground");
    qmlRegisterType<Bullet>("app.components", 1, 0, "Bullet");
    QTEST_ADD_GPU_BLACKLIST_SUPPORT
    QTEST_SET_MAIN_SOURCE_PATH
    return quick_test_main(argc, argv, "example", QUICK_TEST_SOURCE_DIR);
}

