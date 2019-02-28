#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QQmlContext>

#include <QDomDocument>

#include "model/world.h"

#include "elements/elements.h"

int main(int argc, char *argv[])
{
	World::init(QSizeF(3000, 150));
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QApplication app(argc, argv);
	qmlRegisterType<Robot>("app.components", 1, 0, "Robot");
	qmlRegisterType<Hero>("app.components", 1, 0, "Hero");
	qmlRegisterType<GroundItem>("app.components", 1, 0, "Ground");
	qmlRegisterType<Bullet>("app.components", 1, 0, "Bullet");

	QQuickView view(QStringLiteral("qrc:/main.qml"));

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

	view.showMaximized();
	return app.exec();
}
