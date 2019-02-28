#ifndef CHARACTERITEM_H
#define CHARACTERITEM_H

#include <QQuickPaintedItem>
#include <QPropertyAnimation>
#include <QStyleOptionGraphicsItem>

#include "../common.h"

#include "model/elementengine.h"

class Ground;
class Character;

class CharacterItem : public QQuickPaintedItem
{
	Q_OBJECT
	Q_PROPERTY(unsigned int legMovement READ legMovement WRITE setLegMovement)
	Q_PROPERTY(float distance READ distance WRITE setDistance)
public:
	QRectF boundingRect() const override;
	virtual void paint(QPainter *painter) override;

	unsigned int legMovement() const;
	void setLegMovement(unsigned int value);

	float distance() const;
	void setDistance(float value);

	virtual bool contains(QPointF const& point) const override;

protected:
	CharacterItem(Character const& sprites);

private:
	Move moveStatus;
	Character const& sprites;
	unsigned int propLegMovement;
	QPropertyAnimation* legAnimation;
	ElementEngine* engine;

public slots:
	void turnLeft();
	void turnRight();
	void moveRight();
	void moveLeft();
	void stand();
	void kneel();
	void updatePosition();
	void fire();
};

#endif // CHARACTERITEM_H
