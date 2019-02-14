#include "sprite.h"

#include <QPainter>

Sprite::Sprite(QString const& filename):
	image(filename),
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
