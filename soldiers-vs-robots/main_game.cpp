#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QQmlContext>

#include "model/world.h"

#include "elements/elements.h"


int main(int argc, char *argv[])
{
	World::init(QSizeF(3000, 150));
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QApplication app(argc, argv);
	//app.setStyle(new Style(QApplication::style()->objectName()));
	qmlRegisterType<Robot>("app.components", 1, 0, "Robot");
	qmlRegisterType<Hero>("app.components", 1, 0, "Hero");
	qmlRegisterType<GroundItem>("app.components", 1, 0, "Ground");
	qmlRegisterType<Bullet>("app.components", 1, 0, "Bullet");

	QQuickView view(QStringLiteral("qrc:/Game.qml"));
	view.showMaximized();
	return app.exec();
}
