#ifndef CHARACTERITEM_H
#define CHARACTERITEM_H

#include <QQuickPaintedItem>
#include <QPropertyAnimation>
#include <QStyleOptionGraphicsItem>

#include "../common.h"

class Ground;
class Character;

class CharacterItem : public QQuickPaintedItem
{
	Q_OBJECT
	Q_PROPERTY(qreal distance READ distance WRITE setDistance)
	Q_PROPERTY(unsigned int legMovement READ legMovement WRITE setLegMovement)
public:
	QRectF boundingRect() const override;
	virtual void paint(QPainter *painter) override;

	void setDistance(qreal distance);
	qreal distance() const;

	unsigned int legMovement() const;
	void setLegMovement(unsigned int value);

protected:
	CharacterItem(Character const& sprites, Ground const& ground);

private:
	Move moveStatus;
	Direction currentDirection;
	Character const& sprites;
	qreal propDistance;
	unsigned int propLegMovement;
	Ground const& ground;
	QPropertyAnimation* moveAnimation;
	QPropertyAnimation* legAnimation;
	void move(Move status, Direction direction);
	void move(Move status);

public slots:
	void moveRight();
	void moveLeft();
	void stand();
	void kneel();
};

#endif // CHARACTERITEM_H
