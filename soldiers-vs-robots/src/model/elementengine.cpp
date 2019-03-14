#include "elementengine.h"

#include <QDebug>


ElementEngine::ElementEngine(Ground const& ground, QObject *parent) : QObject(parent),
	ground(ground),
	propDistance(0),
	animation(new QPropertyAnimation(this, "distance")),
	currentDirection(Direction::Right)
{
	animation->setDuration(duration(ground.length()));
	animation->setStartValue(propDistance);
	animation->setEndValue(ground.length());
	//connect(animation, &QPropertyAnimation::finished, [=] )
}

void ElementEngine::setDistance(qreal distance)
{
	propDistance = distance;
	emit moved();
}

void ElementEngine::setStartDistance(qreal distance)
{
	propDistance = distance;
	animation->setStartValue(propDistance);
	emit moved();
}

qreal ElementEngine::distance() const
{
	return propDistance;
}

QPointF ElementEngine::position() const
{
	return ground.projection(propDistance);
}

Direction ElementEngine::direction() const
{
	return currentDirection;
}

void ElementEngine::turn(Direction direction)
{
	if (direction == currentDirection)
		return;
	currentDirection = direction;
	emit moved();
}

void ElementEngine::move(Direction direction)
{
	if (direction != currentDirection)
	{
		animation->stop();
		qreal end = endValue(direction);
		qreal const d = qAbs(propDistance - end);
		animation->setDuration(duration(d));
		animation->setStartValue(propDistance);
		animation->setEndValue(end);
	}
	currentDirection = direction;
	if (propDistance == animation->endValue())
		return;
	animation->start();
}

void ElementEngine::stop()
{
	animation->pause();
}

void ElementEngine::forceStop()
{
	animation->stop();
}

qreal ElementEngine::endValue(Direction direction)
{
	if (direction == Direction::Left)
		return 0;
	return ground.length();
}

int ElementEngine::duration(qreal distance)
{
	qreal const speed = 0.111123;
	return int(distance / speed);
}
