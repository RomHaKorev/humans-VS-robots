#ifndef GROUNDITEM_H
#define GROUNDITEM_H

#include <QQuickPaintedItem>
#include <QPainterPath>
#include <QBrush>

#include "../model/ground.h"

class GroundItem : public QQuickPaintedItem
{
	Q_OBJECT
	Q_PROPERTY(QColor color READ color WRITE setColor)
public:
	GroundItem();
	virtual QRectF boundingRect() const override;
	virtual void paint(QPainter *painter) override;

	QColor color() const;

	QPainterPath boundingPath() const;

private:
	Ground const& ground;
	QPainterPath path;
	QBrush brush;
	static QPainterPath buildBackground(QSizeF const& size);
	static QPair<QPointF, QPointF> controlPoints(const QPointF& p0, const QPointF& p1, const QPointF& p2, qreal t=0.25);
	static QPainterPath buildPath(QSizeF const& size);

public slots:
	void setColor(QColor const& color);
};

#endif // GROUNDITEM_H
