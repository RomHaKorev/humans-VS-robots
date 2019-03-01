#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QQmlContext>
#include "src/model/world.h"
#include "src/elements/hero.h"
#include "src/elements/bullet.h"
#include "src/elements/grounditem.h"


int main(int argc, char *argv[])
{
	World::init(QSizeF(3000, 50));
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QApplication app(argc, argv);
	qmlRegisterType<Hero>("app.components", 1, 0, "Hero");
	qmlRegisterType<GroundItem>("app.components", 1, 0, "Ground");
	qmlRegisterType<Bullet>("app.components", 1, 0, "Bullet");

    QQuickView view(QStringLiteral("qrc:/Game.qml"));

	/*GroundItem* groundItem;
	Hero* hero(new Hero());


	QQuickItem *item = view.rootObject();
	groundItem->setParentItem(item);
	groundItem->setX(0);
	groundItem->setY(50);
	hero->setParentItem(groundItem);

	QObject::connect(item, SIGNAL(stand()),
						 hero, SLOT(stand()));
	QObject::connect(item, SIGNAL(moveRight()),
						 hero, SLOT(moveRight()));*/

    //view.showMaximized();

    QWidget* widget = new QWidget();
    widget->setFixedSize(200, 800);
    widget->show();
	return app.exec();
}
