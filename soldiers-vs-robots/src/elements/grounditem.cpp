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

	QRectF const rect = soilPath.boundingRect();

	painter->setRenderHint(QPainter::Antialiasing);
	painter->setPen(Qt::NoPen);
	painter->setBrush(QBrush(0x01A200));
	painter->drawPath(soilPath.translated(0, -5));

	QLinearGradient gradient(rect.topLeft(), rect.bottomLeft()); // diagonal gradient from top-left to bottom-right
	gradient.setColorAt(0, 0x533014);
	gradient.setColorAt(1, 0xB45002);
	painter->setBrush(QBrush(gradient));
	painter->drawPath(soilPath.translated(0, 10));
}

template <typename T> int sgn(T val) {
	return (T(0) < val) - (val < T(0));
}
