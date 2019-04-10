#include "decoration.h"

#include <QPainter>
#include <QDebug>

Decoration::Decoration(int id, QString const& filename, QSize const& size):
	id(id),
	sprite(filename, size)
{}


QPixmap Decoration::pixmap(bool random) const
{
	return sprite.get();
}
