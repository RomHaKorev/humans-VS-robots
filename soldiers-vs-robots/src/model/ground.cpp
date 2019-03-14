#include "ground.h"

#include <QRandomGenerator>
#include <qmath.h>

#include <QDebug>

Ground::Ground(QSizeF const& size):
	pth(Ground::buildPath(size)),
	originSize(size)
{

}

Ground::Ground(Ground const& other):
	pth(other.pth),
	originSize(other.originSize)
{
}

Ground& Ground::operator=(Ground const& other)
{
	this->pth = other.pth;
	this->originSize = other.originSize;
	return *this;
}

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

QPainterPath Ground::buildPath(QSizeF const& size)
{
	QPainterPath pth;
	pth.moveTo(0, size.height()/2);
	pth.lineTo(size.width(), size.height()/2);
	/*qreal height = size.height();
	QPainterPath pth;
	qreal x = 0;
	qreal y = QRandomGenerator::global()->bounded(height);
	pth.moveTo(x, y);
	while (x < size.width())
	{
		//qreal nextY = QRandomGenerator::global()->bounded(size.height());
		qreal nextX = x + QRandomGenerator::global()->bounded(size.width() / 10);
		qreal angle = QRandomGenerator::global()->bounded(20.) - 10;
		qreal boundY = (nextX - x) * qSin(qDegreesToRadians(angle));
		qreal nextY = qMax(20.0, qMin(height, y + boundY));
		qDebug() << angle << nextY;
		//QLineF l(x, y, x + nextX, nextY);
		pth.lineTo(nextX, nextY);
		x += nextX;
		y = nextY;
	}
	pth.lineTo(size.width(), y);
	pth.translate(0, -pth.boundingRect().y() + 20);*/
	return pth;
}

QPointF Ground::startPoint() const
{
	return pth.pointAtPercent(0);
}

QPainterPath const& Ground::path() const
{
	return pth;
}

QSizeF Ground::size() const
{
	//return pth.boundingRect().size();
	return originSize;
}

qreal Ground::length() const
{
	return pth.length();
}

QPointF Ground::projection(qreal distance) const
{
	return path().pointAtPercent(pth.percentAtLength(distance));
}
