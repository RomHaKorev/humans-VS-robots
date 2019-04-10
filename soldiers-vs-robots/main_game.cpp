#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QQmlContext>
#include <QScreen>

#include "model/world.h"

#include "elements/elements.h"
#include "elements/ia.h"
#include "elements/characterfactory.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QScreen *screen = QApplication::screens().at(0);
	int w = screen->availableSize().width();
	int h = screen->availableSize().height();
	World::init(QSizeF(3000, h));
	//app.setStyle(new Style(QApplication::style()->objectName()));
	qmlRegisterType<Robot>("app.components", 1, 0, "Robot");
	qmlRegisterType<Hero>("app.components", 1, 0, "Hero");
	qmlRegisterType<GroundItem>("app.components", 1, 0, "Ground");
	qmlRegisterType<Bullet>("app.components", 1, 0, "Bullet");

	QQuickView view(QStringLiteral("qrc:/Game.qml"));
	view.showMaximized();

	QQuickItem* layer = view.findChild<QQuickItem*>("heroLayer");
	Hero* hero = view.findChild<Hero*>("hero");

	CharacterFactory* factory = new CharacterFactory();
	factory->registerCharacter(hero, 0);
	CharacterItem* robot = factory->createCharacter(CharacterType::Ennemy, 0);
	robot->setDistance(800);
	robot->setParentItem(layer);


	return app.exec();
}
