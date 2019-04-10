#ifndef TREE_H
#define TREE_H

#include <QDir>
#include <QPixmap>
#include "../core/sprite.h"

#include "../common.h"

class Decoration
{
public:
	QPixmap pixmap(bool random) const;
	Decoration(int id, QString const& filename, QSize const& size);

	inline QSizeF size() const { return sprite.size(); }
	inline qreal height() const { return size().height(); }
	int const id;
private:
	Sprite const sprite;
};

#endif // TREE_H
