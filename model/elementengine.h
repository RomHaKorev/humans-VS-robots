#ifndef ELEMENTENGINE_H
#define ELEMENTENGINE_H

#include <QObject>
#include <QPropertyAnimation>

#include "ground.h"
#include "../common.h"

class ElementEngine : public QObject
{
	Q_OBJECT
	Q_PROPERTY(qreal distance READ distance WRITE setDistance NOTIFY moved)
public:
	explicit ElementEngine(Ground const& ground, QObject *parent = nullptr);
	qreal distance() const;
	void setDistance(qreal);
	void setStartDistance(qreal);
	QPointF position() const;
	Direction direction() const;

private:
	Ground const& ground;
	qreal propDistance;
	QPropertyAnimation* animation;
	Direction currentDirection;
	qreal endValue(Direction direction);

	int duration(qreal distance);

signals:
	void moved();

public slots:
	void turn(Direction direction);
	void move(Direction direction);
	void stop();
};

#endif // ELEMENTENGINE_H
