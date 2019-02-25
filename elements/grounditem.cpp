#include "grounditem.h"

#include <QPainter>

#include <stdlib.h>
#include <time.h>

#include <QRandomGenerator>

#include "../model/ground.h"
#include "../model/world.h"

#include <QDebug>


GroundItem::GroundItem(): QQuickPaintedItem(),
  ground(*World::ground())
{
	setSize(ground.size());
}

QRectF GroundItem::boundingRect() const
{
	return QRectF(QPointF(0, 0), size());
}

void GroundItem::paint(QPainter *painter)
{

	QPainterPath const gr(ground.path());
	QPainterPath soilPath;
	soilPath.moveTo(gr.pointAtPercent(1));
	soilPath.lineTo(boundingRect().bottomRight());
	soilPath.lineTo(boundingRect().bottomLeft());
	soilPath.lineTo(gr.pointAtPercent(0));
	soilPath.addPath(gr);
	soilPath.closeSubpath();

	painter->save();
	painter->setRenderHint(QPainter::Antialiasing);
	painter->setPen(Qt::NoPen);
	painter->setBrush(QBrush(QPixmap(":/images/world/grass.png")));
	painter->drawPath(soilPath);
	painter->setBrush(QBrush(QPixmap(":/images/world/soil.png")));
	painter->drawPath(soilPath.translated(0, 10));
	painter->restore();
	painter->drawRect(boundingRect());
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
