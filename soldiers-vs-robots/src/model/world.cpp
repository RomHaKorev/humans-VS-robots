#include "world.h"

World::World(QSizeF const& size) : QObject(),
	m_ground(new Ground((size)))
{
}

void World::init(QSizeF const& size)
{
	instance().reset(size);
}

void World::reset(QSizeF const& size)
{
	m_ground = new Ground(size);
}

Ground* World::ground()
{
	return instance().m_ground;
}

ElementEngine* World::createEngine(QObject* parent) const
{
	return new ElementEngine(*m_ground, parent);
}


World& World::instance(QSizeF const& size)
{
	static World instance(size);
	if (size.isValid())
		instance.reset(size);
	return instance;
}


ElementEngine* World::engine(QObject* parent)
{
	return instance().createEngine(parent);
}
