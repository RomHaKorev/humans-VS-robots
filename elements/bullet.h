#ifndef BULLET_H
#define BULLET_H

#include <QQuickPaintedItem>

#include "../common.h"

class QPropertyAnimation;

class Bullet : public QQuickPaintedItem
{
	Q_OBJECT
	Q_PROPERTY(QPointF position READ position WRITE setPosition)
public:
	Bullet();
	Bullet(QPointF const& position, Direction direction, QQuickItem* shooter, QQuickItem* parent=nullptr);

	QRectF boundingRect() const override;
	virtual void paint(QPainter *painter) override;
public slots:
	void setPosition(QPointF const& position);

private:
	QPropertyAnimation* animation;
	QQuickItem const* const shooter;
	int duration(qreal distance) const;
};

#endif // BULLET_H
