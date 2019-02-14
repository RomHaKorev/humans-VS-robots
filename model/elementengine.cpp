#include "elementengine.h"

ElementEngine::ElementEngine(Ground const& ground, QObject *parent) : QObject(parent),
	ground(ground),
	propDistance(0),
	animation(new QPropertyAnimation(this, "distance")),
	position(ground.startPoint())
{
	animation->setDuration(90000);
	animation->setStartValue(0.0);
	animation->setEndValue(ground.length());
}

void ElementEngine::setDistance(qreal distance)
{
	propDistance = distance;
	position = ground.projection(distance);
	emit moved();
}

qreal ElementEngine::distance() const
{
	return propDistance;
}


void ElementEngine::moveLeft()
{

}

void ElementEngine::moveRight()
{
	animation->start();
}

void ElementEngine::stop()
{
	animation->pause();
}
