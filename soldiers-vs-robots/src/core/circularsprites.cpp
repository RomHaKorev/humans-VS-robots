#include "circularsprites.h"

#include <QDebug>

CircularSprites::CircularSprites(QDir const& directory, QSize const& size):
	buffer(CircularSprites::loadSprites(directory, size))
{}

QPixmap const& CircularSprites::at(unsigned int step, Direction direction) const
{
	return buffer.at(step % buffer.size()).get(direction);
}


std::vector<Sprite> CircularSprites::loadSprites(QDir const& directory, QSize const& size)
{
	std::vector<Sprite> buffer;
	for(QString const& filename: directory.entryList(QDir::Files, QDir::Name))
	{
		Sprite const pix(directory.filePath(filename), size);
		buffer.push_back(pix);
	}
	return buffer;
}

unsigned int CircularSprites::size() const
{
	return buffer.size();
}
