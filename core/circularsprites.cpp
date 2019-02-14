#include "circularsprites.h"

#include <QDebug>

CircularSprites::CircularSprites(QDir const& directory):
	buffer(CircularSprites::loadSprites(directory))
{}

QPixmap const& CircularSprites::at(unsigned int step, Direction direction) const
{
	return buffer.at(step % buffer.size()).get(direction);
}


std::vector<Sprite> CircularSprites::loadSprites(QDir const& directory)
{
	std::vector<Sprite> buffer;
	for(QString const& filename: directory.entryList(QDir::Files, QDir::Name))
	{
		Sprite const pix(directory.filePath(filename));
		buffer.push_back(pix);
	}
	return buffer;
}

unsigned int CircularSprites::size() const
{
	return buffer.size();
}
