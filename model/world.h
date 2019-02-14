#ifndef WORLD_H
#define WORLD_H

#include <QObject>

class World : public QObject
{
	Q_OBJECT
public:
	World(World const&) = delete;
	void operator=(World const&) = delete;
private:
	World();
	static World& instance();
};

#endif // WORLD_H
