#include "decoration.h"

#include <QPainter>
#include <QDebug>

Decoration::Decoration(QString const& filename):
	sprite(filename)
{}


QPixmap Decoration::pixmap(bool random) const
{
	return sprite.get();
}
