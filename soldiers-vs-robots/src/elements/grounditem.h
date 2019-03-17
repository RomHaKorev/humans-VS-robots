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
	virtual void paint(QPainter* painter) override;

	QColor color() const;

private:
	Ground const& ground;
	QBrush brush;
	QPixmap const background;

	QPixmap buildBackground(QSizeF const& size);
	static QPainterPath buildBackgroundShape(QSizeF const& size);
	static QPair<QPointF, QPointF> controlPoints(QPointF const& p0, QPointF const& p1, QPointF const& p2, qreal t=0.25);
	static QPainterPath buildPath(QSizeF const& size);
	static QPainterPath boundingPath(QPainterPath const& path, QSizeF const& size);

public slots:
	void setColor(QColor const& color);
};

#endif // GROUNDITEM_H
