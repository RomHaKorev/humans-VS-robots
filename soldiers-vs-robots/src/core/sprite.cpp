#include "sprite.h"

#include <QPainter>

QPixmap load(QString const& path, QSize const& size)
{
	QPixmap pix(path);
	if (!size.isNull())
		return pix.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
	return pix;
}

Sprite::Sprite(QString const& filename, QSize const& size):
	image(load(filename, size)),
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
