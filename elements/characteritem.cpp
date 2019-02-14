#include "characteritem.h"
#include "../model/character.h"

#include "../model/ground.h"

#include <QPainter>
#include <QPropertyAnimation>


CharacterItem::CharacterItem(Character const& sprites, Ground const& ground):
	QQuickPaintedItem(),
	moveStatus(Move::Standing),
	currentDirection(Direction::Right),
	sprites(sprites),
	propDistance(0.0),
	propLegMovement(0),
	ground(ground)
{
	moveAnimation = new QPropertyAnimation(this, "distance");
	moveAnimation->setDuration(90000);
	moveAnimation->setStartValue(0.0);
	moveAnimation->setEndValue(ground.length());
	legAnimation = new QPropertyAnimation(this, "legMovement");
	legAnimation->setDuration(500);
	legAnimation->setStartValue(0);
	legAnimation->setEndValue(sprites.runStepCount());
	legAnimation->setLoopCount(-1);

	setSize(QSizeF(100, 100));
	setX(0);
	setY(0);
	//setPixmap(sprites.pixmap(moveStatus, currentDirection, propLegMovement));
}

QRectF CharacterItem::boundingRect() const
{
	return QRectF(QPointF(0, 0), QSizeF(100, 100));
}

void CharacterItem::paint(QPainter *painter)
{
	painter->setRenderHint(QPainter::Antialiasing);
	sprites.paint(*painter, moveStatus, currentDirection, propLegMovement);
}

void CharacterItem::setDistance(qreal distance)
{
	propDistance = distance;
	QPointF const position(ground.projection(distance) - QPointF(0, boundingRect().height()));
	setX(position.x());
	setY(position.y());
}

qreal CharacterItem::distance() const
{
	return propDistance;
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

void CharacterItem::move(Move status)
{
	move(status, currentDirection);
}

void CharacterItem::move(Move status, Direction direction)
{
	moveStatus = status;
	if (currentDirection != direction)
		propLegMovement = 0;
	currentDirection = direction;
	//setPixmap(sprites.pixmap(moveStatus, currentDirection, propLegMovement));
}

void CharacterItem::moveRight()
{
	move(Move::Moving, Direction::Right);
	moveAnimation->start();
	legAnimation->start();
}

void CharacterItem::moveLeft()
{
	move(Move::Moving, Direction::Left);
}

void CharacterItem::stand()
{
	move(Move::Standing);
	moveAnimation->pause();
	legAnimation->stop();
	//setPixmap(sprites.pixmap(moveStatus, currentDirection, propLegMovement));
}

void CharacterItem::kneel()
{
	move(Move::Kneeling);
	moveAnimation->pause();
	legAnimation->stop();
	//setPixmap(sprites.pixmap(moveStatus, currentDirection, propLegMovement));
}
