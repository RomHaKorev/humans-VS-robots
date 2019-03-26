#include "graphicseffects.h"

#include <QGraphicsScene>
#include <QGraphicsEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>

namespace GraphicsEffects
{
QPixmap applyEffectToImage(QPixmap const& src, QGraphicsEffect *effect, int extent)
{
	if(src.isNull())
		return QPixmap();   //No need to do anything else!
	if(!effect)
		return src;             //No need to do anything else!

	QGraphicsScene scene;
	QGraphicsPixmapItem item;
	item.setPixmap(src);
	item.setGraphicsEffect(effect);
	scene.addItem(&item);
	QSize const targetSize(src.size() + QSize(extent * 2, extent * 2));
	QPixmap res(targetSize);
	res.fill(Qt::transparent);
	QPainter ptr(&res);
	scene.render(&ptr, QRectF(), QRectF(QPointF(-extent, -extent), targetSize));
	return res;
}

void drawWithBlurEffect(QPainter& painter, QPainterPath const& path)
{
	QPixmap pix(path.boundingRect().size().toSize() + QSize(painter.pen().width(), painter.pen().width()));
	QPainter p(&pix);
	p.setPen(painter.pen());
	p.setBrush(painter.brush());
	p.setClipPath(painter.clipPath());
	p.drawPath(path);
	QGraphicsBlurEffect* blurEffect = new QGraphicsBlurEffect();
	blurEffect->setBlurRadius(p.pen().width()/2);
	QPixmap const blurry = applyEffectToImage(pix, blurEffect);
	//blurEffect->deleteLater();
	painter.drawPixmap(0, 0, blurry);
}
}
