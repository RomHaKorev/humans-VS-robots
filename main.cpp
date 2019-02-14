#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QQmlContext>



#include "elements/hero.h"
#include "elements/grounditem.h"

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QApplication app(argc, argv);

	Ground* ground(new Ground(QSizeF(10000, 500)));
	GroundItem* groundItem(new GroundItem(*ground));
	Hero* hero(new Hero(*ground));

	QQuickView view(QStringLiteral("qrc:/main.qml"));
	QQuickItem *item = view.rootObject();
	groundItem->setParentItem(item);
	groundItem->setX(0);
	groundItem->setY(50);
	hero->setParentItem(groundItem);

	QObject::connect(item, SIGNAL(stand()),
						 hero, SLOT(stand()));
	QObject::connect(item, SIGNAL(moveRight()),
						 hero, SLOT(moveRight()));

	view.show();
	return app.exec();
}
