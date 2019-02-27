#if 0
#include "gameworld.h"

#include <QEvent>
#include <QTouchEvent>
#include <QDebug>



GameWorld::GameWorld(QWidget *parent) : QGraphicsView(parent),
	scene(new QGraphicsScene()),
	ground(new Ground(QSizeF(10000, 500))),
	groundItem(new GroundItem(*ground)),
	hero(new Hero(*ground))
{
	setScene(scene);
	scene->addItem(groundItem);
	//scene->addItem(hero);

	Btn* btn = new Btn();
	scene->addItem(btn);
}

void GameWorld::move()
{
	hero->moveRight();
}

void GameWorld::stop()
{
	hero->stand();
}

/*void GameWorld::mousePressEvent(QMouseEvent *event)
{
	hero->moveRight();
}

void GameWorld::mouseReleaseEvent(QMouseEvent *event)
{
	hero->stand();
}*/

#endif
