#include "spritesmanager.h"

#include "../model/character.h"

#include <QString>
#include <QDir>
#include <QDebug>


SpritesManager::SpritesManager(QString const& resPath):
	heroes(loadCharacters(QDir(resPath).filePath("heroes"))),
	robots(loadCharacters(QDir(resPath).filePath("enemies")))
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

Character const& SpritesManager::robot(unsigned int id)
{
	return instance().robots.at(id);
}

std::vector<Character> SpritesManager::loadCharacters(QDir const& directory)
{
	std::vector<Character> l;
	for(QString const& filename: directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
	{
		qDebug() << directory.filePath(filename);
		l.push_back(Character(directory.filePath(filename)));
	}
	return l;
}
