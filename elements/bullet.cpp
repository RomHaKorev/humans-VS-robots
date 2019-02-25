#include "bullet.h"

#include <QPainter>
#include <QPropertyAnimation>

Bullet::Bullet(QPointF const& position, Direction direction, QQuickItem* shooter, QQuickItem* parent): QQuickPaintedItem(parent),
	animation(new QPropertyAnimation(this, "position")),
	shooter(shooter)
{
	setPosition(position);
	animation->setStartValue(position);
	QPointF endPoint(parentItem()->width(), position.y());
	if (direction == Direction::Left)
		endPoint.setX(0);
	animation->setEndValue(endPoint);
	animation->setDuration(duration(endPoint.x() - position.x()));
	animation->start();
	connect(animation, &QPropertyAnimation::finished, this, &Bullet::deleteLater);
	setSize(QSizeF(20, 10));
}

Bullet::Bullet(): QQuickPaintedItem(),
	shooter(nullptr)
{
	setSize(QSizeF(20, 10));
}

void Bullet::setPosition(QPointF const& position)
{
	QQuickPaintedItem::setPosition(position);
	for (QQuickItem* sibling: parentItem()->childItems())
	{
//		qDebug() << Q_FUNC_INFO << sibling << this << shooter << parent() << sibling->contains(position);
		if (sibling == this || sibling == shooter)
			continue;
		if (sibling->contains(position))
		{
			animation->stop();
			deleteLater();
//			qDebug() << "----";
			return;
		}
	}
}

QRectF Bullet::boundingRect() const
{
	return QRectF(QPointF(0, -height()/2), size());
}

void Bullet::paint(QPainter *painter)
{
	painter->setPen(Qt::NoPen);
	painter->setBrush(QColor(0xbb981f));
	painter->drawRect(boundingRect());
}

int Bullet::duration(qreal distance) const
{
	qreal const speed = 0.75;
	return int(qAbs(distance) / speed);
}
