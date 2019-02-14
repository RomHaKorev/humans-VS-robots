#ifndef GROUNDITEM_H
#define GROUNDITEM_H

#include <QQuickPaintedItem>
#include <QPainterPath>

#include "../model/ground.h"

class GroundItem : public QQuickPaintedItem
{
public:
	GroundItem(Ground const& ground);
	virtual QRectF boundingRect() const override;
	virtual void paint(QPainter *painter) override;
private:
	Ground const& ground;
//private slots:
//	void sizeHasChanged();
};

#endif // GROUNDITEM_H
