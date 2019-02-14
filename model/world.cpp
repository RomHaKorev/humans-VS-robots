#include "world.h"

World::World() : QObject()
{

}


World const& World::instance()
{
	static World const instance();
	return instance;
}

World const& World::instance()
{
	static World const instance();
	return instance;
}
