#include "sprite.h"

#include <QPainter>

QPixmap load(QString const& path)
{
	QPixmap pix(path);
	return pix;
}

Sprite::Sprite(QString const& filename):
	image(load(filename).scaled(characterSize, Qt::KeepAspectRatio, Qt::SmoothTransformation)),
	reversedImage(image.transformed(QTransform().scale(-1, 1), Qt::SmoothTransformation))
{}

QPixmap const& Sprite::get(Direction direction) const
{
	if (direction == Direction::Left)
	{
		return reversedImage;
	}
	return image;
}
