#ifndef GROUND_H
#define GROUND_H

#include <QPainterPath>

class Ground
{
public:
	Ground(QSizeF const& size);
	Ground(Ground const& other);
	QPointF projection(qreal distance) const;
	QPainterPath const& path() const;
	QSizeF size() const;
	qreal length() const;
	QPointF startPoint() const;

	Ground& operator=(Ground const& other);
private:
	QPainterPath pth;
	QSizeF originSize;
    static QPainterPath buildPath(QSizeF const& size);
};

#endif // GROUND_H
