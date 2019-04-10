#include "spritesmanager.h"

#include "../model/character.h"
#include "../model/decoration.h"

#include <QString>
#include <QDir>
#include <QRandomGenerator>
#include <QDebug>


SpritesManager::SpritesManager(QString const& resPath):
	heroes(loadCharacters(QDir(resPath).filePath("heroes"))),
	robots(loadCharacters(QDir(resPath).filePath("enemies"))),
	decorations(loadWorldElements(QDir(resPath).filePath("world/trees")))
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

Decoration const& SpritesManager::decoration()
{
	std::size_t const id = QRandomGenerator::global()->bounded(quint32(instance().decorations.size()));
	Decoration const& d = instance().decorations.at(id);
	return d;
}

Decoration const& SpritesManager::decoration(int id)
{
	Decoration const& d = instance().decorations.at(id);
	return d;
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

std::vector<Decoration> SpritesManager::loadWorldElements(QDir const& directory)
{
	std::vector<Decoration> l;
	int id = 0;
	for(QString const& filename: directory.entryList())
	{
		l.push_back(Decoration(id, directory.filePath(filename), treeSize));
		++id;
	}
	return l;
}
