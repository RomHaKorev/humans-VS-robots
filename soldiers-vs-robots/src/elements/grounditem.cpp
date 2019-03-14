#include "grounditem.h"

#include <QPainter>

#include <stdlib.h>
#include <time.h>

#include <QRandomGenerator>
#include <qmath.h>


#include "../model/ground.h"
#include "../model/world.h"
#include "graphicseffects.h"

#include <QDebug>


GroundItem::GroundItem(): QQuickPaintedItem(),
  ground(*World::ground()),
  path(buildBackground(ground.size()))
{
	//setSize(QSizeF(ground.length(), 200));
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

QPainterPath GroundItem::boundingPath() const
{
	QPainterPath pth(path);
	pth.lineTo(size().width(), 0);
	pth.lineTo(size().width(), size().height());
	pth.lineTo(0, size().height());
	pth.lineTo(0, 0);
	pth.addRect(0, pth.boundingRect().height(),
				pth.boundingRect().width(), size().height() - pth.boundingRect().height());
	return pth;
}

void GroundItem::paint(QPainter *painter)
{
	painter->setRenderHint(QPainter::Antialiasing);
	painter->setPen(Qt::NoPen);
	//QRectF const rect = path.boundingRect();
	//QLinearGradient gradient(rect.topLeft(), rect.bottomLeft()); // diagonal gradient from top-left to bottom-right
	//gradient.setColorAt(0, 0x77b643);
	//gradient.setColorAt(1, 0x2e6d67);
	//painter->setBrush(QBrush(0x77b643));
	painter->setBrush(QBrush(0x77b643));
	QPainterPath const& bounds(boundingPath());
	painter->drawPath(bounds);
	painter->setClipPath(bounds);

	painter->setBrush(Qt::NoBrush);
	painter->setPen(QPen(QBrush(0x2e6d67), 24));
	GraphicsEffects::drawWithBlurEffect(painter, path);
}

QPainterPath GroundItem::buildBackground(QSizeF const& size)
{
	QPainterPath pathFirstPlan = buildPath(QSizeF(size.width(), size.height() / 4));
	return pathFirstPlan;
}


QPainterPath GroundItem::buildPath(const QSizeF &size)
{
	QPainterPath pth;
	qreal x = 0;

	QList<QPointF> points;
	points << QPointF(0, 0);
	while (x < size.width())
	{
		qreal const nextX = 75 + QRandomGenerator::global()->bounded(75);
		qreal const nextY = QRandomGenerator::global()->bounded(size.height());
		points << QPointF(x + nextX, nextY);
		x += nextX;
	}

	QPair<QPointF, QPointF> pair = controlPoints(points.at(0), points.at(1), points.at(2));
	QPointF p0 = pair.second;
	pth.moveTo(0, 0);
	pth.lineTo(p0);
	for (int i = 2; i != points.count() - 1; ++i)
	{
		QPair<QPointF, QPointF> pair = controlPoints( points.at(i - 1), points.at(i), points.at(i + 1));
		pth.cubicTo( p0, pair.first, points.at( i ) );
		p0 = pair.second;
	}
	pth.lineTo(size.width(), 0);
	return pth;
}

QPair<QPointF, QPointF> GroundItem::controlPoints( const QPointF& p0, const QPointF& p1, const QPointF& p2, qreal t )
{
	QPair<QPointF, QPointF> pair;
	qreal d01 = qSqrt( ( p1.x() - p0.x() ) * ( p1.x() - p0.x() ) + ( p1.y() - p0.y() ) * ( p1.y() - p0.y() ) );
	qreal d12 = qSqrt( ( p2.x() - p1.x() ) * ( p2.x() - p1.x() ) + ( p2.y() - p1.y() ) * ( p2.y() - p1.y() ) );

	qreal fa = t * d01 / ( d01 + d12 );
	qreal fb = t * d12 / ( d01 + d12 );

	qreal c1x = p1.x() - fa * ( p2.x() - p0.x() );
	qreal c1y = p1.y() - fa * ( p2.y() - p0.y() );
	qreal c2x = p1.x() + fb * ( p2.x() - p0.x() );
	qreal c2y = p1.y() + fb * ( p2.y() - p0.y() );

	pair.first = QPointF( c1x, c1y );
	pair.second = QPointF( c2x, c2y );

	return pair;
}



