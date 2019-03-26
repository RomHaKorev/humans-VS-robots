#ifndef SPRITESMANAGER_H
#define SPRITESMANAGER_H

class Character;
class Decoration;
class QString;
class QDir;

#include <vector>

class SpritesManager
{
public:
	static Character const& hero(unsigned int id);
	static Character const& robot(unsigned int id);
	static Decoration const& decoration();
    static Decoration const& decoration(int id);
	SpritesManager(SpritesManager const&) = delete;
	void operator=(SpritesManager const&) = delete;
private:
	SpritesManager(QString const& resPath);
	static SpritesManager const& instance();

	static std::vector<Decoration> loadWorldElements(QDir const& directory);
	static std::vector<Character> loadCharacters(QDir const& directory);
	Character loadCharacter(QDir const& directory);
	//Decoration const& loadTree(QDir const& directory);
	std::vector<Character> const heroes;
	std::vector<Character> const robots;
	std::vector<Decoration> const decorations;
};

#endif // SPRITESMANAGER_H
