#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QQmlContext>

#include <QDomDocument>

#include "model/world.h"

#include "elements/hero.h"
#include "elements/bullet.h"
#include "elements/grounditem.h"

int main(int argc, char *argv[])
{
	World::init(QSizeF(3000, 50));
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QApplication app(argc, argv);

	QDomDocument domDocument;

	QString content = R"C(<?xml version="1.0" encoding="UTF-8"?>
			<root>
				<Tag1>
					<Attribute1>5</Attribute1>
					<Attribute2>5</Attribute2>
				</Tag1>
				<Settings\\it.server.com>
					<Attribute1>1</Attribute1>
				</Settings\\it.server.com>
			</root>)C";
		content.replace("\\", "_");
	   QString errorStr;
	   int errorLine;
	   int errorColumn;

	   if (!domDocument.setContent(content, false, &errorStr, &errorLine, &errorColumn))
		   qDebug() << errorStr << errorLine << errorColumn;

	return 0;

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
