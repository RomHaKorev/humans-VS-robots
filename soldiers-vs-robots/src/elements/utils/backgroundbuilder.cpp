#include "backgroundbuilder.h"

#include <QRandomGenerator>
#include <QPainter>
#include <QDebug>

#include <qmath.h>

#include "../../core/spritesmanager.h"
#include "../../model/decoration.h"

#include "graphicseffects.h"

QPainterPath BackgroundBuilder::boundingPath(QPainterPath const& path, QSizeF const& size)
{
    QPainterPath pth(path);
    pth.lineTo(size.width(), 0);
    pth.lineTo(size.width(), size.height());
    pth.lineTo(0, size.height());
    pth.lineTo(0, 0);
    pth.addRect(0, pth.boundingRect().height(),
                pth.boundingRect().width(), size.height() - pth.boundingRect().height());
    return pth;
}

QPainterPath BackgroundBuilder::buildBackgroundShape(QSizeF const& size)
{
    QPainterPath pathFirstPlan = buildPath(QSizeF(size.width(), size.height() / 4));
    return pathFirstPlan;
}


QPixmap BackgroundBuilder::buildBackground(QSizeF const& size)
{
    QPainterPath const path(buildBackgroundShape(size));
    QPainterPath const& bounds(boundingPath(path, size));

    QPixmap backgroundPixmap(size.toSize() + QSize(0, 100));
    backgroundPixmap.fill(Qt::transparent);

    QPainter painter(&backgroundPixmap);
    painter.translate(0, 100);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(0x77b643));

    paintDecoration(painter, path, 80, 3);

    painter.drawPath(bounds);
    painter.save();
    painter.setClipPath(bounds);

    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(QBrush(0x2e6d67), 24));

    GraphicsEffects::drawWithBlurEffect(painter, path);

    painter.restore();

    /*for (double delta = 0; delta < 100; delta += QRandomGenerator::global()->bounded(1, 5))
    {
        Decoration const& deco = SpritesManager::decoration();
        QPointF p = path.pointAtPercent(delta/100.0);
        QPixmap const pix(deco.pixmap(true).scaledToHeight(100, Qt::SmoothTransformation));
        painter.drawPixmap(p - QPointF(0, pix.height()) * 0.7, pix);
    }*/

    paintDecoration(painter, path, 70, 5);

    return backgroundPixmap;
}


int farFirst(QPair<QRect, int> const& left, QPair<QRect, int> const& right)
{
    QPoint const& rLeft = left.first.bottomLeft();
    QPoint const& rRight = right.first.bottomLeft();
    if (rLeft.y() < rRight.y())
        return -1;
    else if (rLeft.y() == rRight.y())
        return 0;
    else
        return 1;


}

void BackgroundBuilder::paintDecoration(QPainter& painter, QPainterPath const& path, int offsetJitter, quint32 density)
{
    QList<QPair<QRect, int> > decorations;
    for (double delta = 0; delta < 100; delta += QRandomGenerator::global()->bounded(quint32(1), density))
    {
        int const jitter = QRandomGenerator::global()->bounded(offsetJitter, int(100));
        Decoration const& deco = SpritesManager::decoration();
        QPoint const p = path.pointAtPercent(delta/100.0).toPoint();
        //QPixmap const pix(deco.pixmap(true).scaledToHeight(jitter, Qt::SmoothTransformation));
        //painter.drawPixmap(p - QPointF(0, pix.height() * 0.7), pix);
        decorations << QPair<QRect, int>(QRect(p - QPoint(10, int(double(deco.height()) * 0.7)), QSize(0, jitter)), deco.id);
    }

    std::sort(decorations.begin(), decorations.end(), farFirst);

    for (QPair<QRect, int> const& decoration: decorations) {
        QRect const& r = decoration.first;
        int const& id = decoration.second;
        QPixmap const pix = SpritesManager::decoration(id).pixmap(true).scaledToHeight(r.height(), Qt::SmoothTransformation);
        qDebug() << r.bottomLeft();
        painter.drawPixmap(r.topLeft(), pix);
    }


}


QPainterPath BackgroundBuilder::buildPath(QSizeF const& size)
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

QPair<QPointF, QPointF> BackgroundBuilder::controlPoints(QPointF const& p0, QPointF const& p1, QPointF const& p2, qreal t)
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
