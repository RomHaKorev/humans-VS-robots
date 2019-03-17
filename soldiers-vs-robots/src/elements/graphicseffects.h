#ifndef GRAPHICSEFFECTS_H
#define GRAPHICSEFFECTS_H

#include <QPixmap>

class QGraphicsEffect;


namespace GraphicsEffects
{
	QPixmap applyEffectToImage(QPixmap const& src, QGraphicsEffect *effect, int extent=0);
	void drawWithBlurEffect(QPainter& painter, QPainterPath const& path);
}

#endif // GRAPHICSEFFECTS_H
