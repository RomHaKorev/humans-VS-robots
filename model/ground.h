#ifndef GROUND_H
#define GROUND_H

#include <QPainterPath>

class Ground
{
public:
	Ground(QSizeF const& size);
	QPointF projection(qreal distance) const;
	QPainterPath const& path() const;
	QSizeF size() const;
	qreal length() const;
	QPointF startPoint() const;
private:
	QPainterPath const pth;
	QSizeF const originSize;
	static QPainterPath buildPath(QSizeF const& size);
};

#endif // GROUND_H
