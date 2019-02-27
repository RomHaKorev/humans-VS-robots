#include "characteritem.h"
#include "../model/character.h"

#include "../model/ground.h"
#include "../model/world.h"

#include <QPainter>
#include <QBitmap>
#include <QRegion>
#include <QPropertyAnimation>
#include <QtSvg/QSvgRenderer>

#include "bullet.h"


CharacterItem::CharacterItem(Character const& sprites):
	QQuickPaintedItem(),
	moveStatus(Move::Standing),
	sprites(sprites),
	propLegMovement(0),
	engine(World::newEngine(this))
{
	legAnimation = new QPropertyAnimation(this, "legMovement");
	legAnimation->setDuration(500);
	legAnimation->setStartValue(0);
	legAnimation->setEndValue(sprites.runStepCount());
	legAnimation->setLoopCount(-1);

	setSize(characterSize);
	connect(engine, &ElementEngine::moved, this, &CharacterItem::updatePosition);

	updatePosition();
}

QRectF CharacterItem::boundingRect() const
{
	return QRectF(QPointF(0, 0), size());
}

void CharacterItem::paint(QPainter *painter)
{
	painter->setRenderHint(QPainter::Antialiasing);
	sprites.paint(*painter, moveStatus, engine->direction(), propLegMovement);
}

unsigned int CharacterItem::legMovement() const
{
	return propLegMovement;
}

void CharacterItem::setLegMovement(unsigned int value)
{
	propLegMovement = value;
	update();
}


void CharacterItem::moveRight()
{
	moveStatus = Move::Moving;
	engine->move(Direction::Right);
	legAnimation->start();
}

void CharacterItem::moveLeft()
{
	moveStatus = Move::Moving;
	engine->move(Direction::Left);
	legAnimation->start();
}

void CharacterItem::stand()
{
	moveStatus = Move::Standing;
	engine->stop();
	legAnimation->stop();
	update();
}

void CharacterItem::kneel()
{
	moveStatus = Move::Kneeling;
	engine->stop();
	legAnimation->stop();
	update();
}

void CharacterItem::updatePosition()
{
	QPointF const pos = engine->position();
	setX(pos.x() - width()/2);
	setY(pos.y() - height());
}

void CharacterItem::fire()
{
	QPointF offset(width(), height()/2 -5);
	if (engine->direction() == Direction::Left)
		offset.setX(-10);
	if (moveStatus == Move::Kneeling)
		offset.setY(height()/2);
	Bullet* b = new Bullet(position() + offset, engine->direction(), this, parentItem());
	b->setParent(parent());
}

bool CharacterItem::contains(QPointF const& point) const
{
	QBitmap const b(sprites.pixmap(moveStatus, engine->direction(), propLegMovement));
	QRegion region(b);
	region.translate(position().toPoint());
	return region.contains(point.toPoint());
}
