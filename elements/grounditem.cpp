#include "grounditem.h"

#include <QPainter>

#include <stdlib.h>
#include <time.h>

#include <QRandomGenerator>

#include "../model/ground.h"

#include <QDebug>

GroundItem::GroundItem(Ground const& ground): QQuickPaintedItem(),
  ground(ground)
{
	setSize(ground.size());
	qDebug() << Q_FUNC_INFO << size();
	//connect(this, &QQuickPaintedItem::widthChanged, this, &GroundItem::sizeHasChanged);
	//connect(this, &QQuickPaintedItem::heightChanged, this, &GroundItem::sizeHasChanged);
}

QRectF GroundItem::boundingRect() const
{
	return QRectF(QPointF(0, 0), size());
}

void GroundItem::paint(QPainter *painter)
{
	painter->drawRect(boundingRect());
	painter->setPen(Qt::red);
	painter->drawRect(ground.path().boundingRect());
	painter->setRenderHint(QPainter::Antialiasing);
	painter->drawPath(ground.path());
}

/*GroundItem::GroundItem(QSizeF const& size): QQuickPaintedItem ()
{
	srand (time_t(nullptr));
	setSize(size);
	connect(this, &QQuickPaintedItem::widthChanged, this, &GroundItem::sizeHasChanged);
	connect(this, &QQuickPaintedItem::heightChanged, this, &GroundItem::sizeHasChanged);
}*/

/*void GroundItem::paint(QPainter *painter)
{
	painter->setRenderHint(QPainter::Antialiasing);
	painter->drawRect(QRectF(QPointF(0,0), size()));
	painter->drawPath(ground.path());
}*/

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}

/*void GroundItem::sizeHasChanged()
{
	Ground::reset(size());
	update();
}*/
