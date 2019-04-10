#ifndef BACKGROUNDBUILDER_H
#define BACKGROUNDBUILDER_H

#include <QPixmap>

namespace BackgroundBuilder
{
QPixmap buildBackground(QSizeF const& size);
QPainterPath buildBackgroundShape(QSizeF const& size);
QPair<QPointF, QPointF> controlPoints(QPointF const& p0, QPointF const& p1, QPointF const& p2, qreal t=0.25);
QPainterPath buildPath(QSizeF const& size);
QPainterPath boundingPath(QPainterPath const& path, QSizeF const& size);

void paintDecoration(QPainter& painter, QPainterPath const& path, double offsetJitter, quint32 density);

};

#endif // BACKGROUNDBUILDER_H
