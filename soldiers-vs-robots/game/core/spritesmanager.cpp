#include "spritesmanager.h"

#include "../model/character.h"

#include <QString>
#include <QDir>


SpritesManager::SpritesManager(QString const& resPath):
	heroes(loadCharacters(QDir(resPath).filePath("heroes")))
{

}


SpritesManager const& SpritesManager::instance()
{
	static SpritesManager const instance(":/images/");
	return instance;
}

Character const& SpritesManager::hero(unsigned int id)
{
	return instance().heroes.at(id);
}

std::vector<Character> SpritesManager::loadCharacters(QDir const& directory)
{
	std::vector<Character> l;
	for(QString const& filename: directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
	{
		l.push_back(Character(directory.filePath(filename)));
	}
	return l;
}
