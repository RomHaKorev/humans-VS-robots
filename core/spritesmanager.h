#ifndef SPRITESMANAGER_H
#define SPRITESMANAGER_H

class Character;
class QString;
class QDir;

#include <vector>

class SpritesManager
{
public:
	static Character const& hero(unsigned int id);
	SpritesManager(SpritesManager const&) = delete;
	void operator=(SpritesManager const&) = delete;
private:
	SpritesManager(QString const& resPath);
	static SpritesManager const& instance();

	static std::vector<Character> loadCharacters(QDir const& directory);
	Character loadCharacter(QDir const& directory);
	std::vector<Character> const heroes;
};

#endif // SPRITESMANAGER_H
