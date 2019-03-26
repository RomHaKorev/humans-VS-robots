#include "grounditem.h"

#include <QPainter>

#include "../model/ground.h"
#include "../model/world.h"
#include "utils/backgroundbuilder.h"

#include <QDebug>


GroundItem::GroundItem(): QQuickPaintedItem(),
  ground(*World::ground()),
  background(BackgroundBuilder::buildBackground(ground.size()))
{
	setSize(ground.size());

}

QColor GroundItem::color() const
{
	return brush.color();
}
void GroundItem::setColor(QColor const& color)
{
	brush = QBrush(color);
}

QRectF GroundItem::boundingRect() const
{
	return QRectF(QPointF(0, 0), size());
}



void GroundItem::paint(QPainter *painter)
{
	painter->setRenderHint(QPainter::Antialiasing);
	painter->drawPixmap(0, 0, background);
}





