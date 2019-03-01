#ifndef WORLD_H
#define WORLD_H

#include <QObject>
#include "elementengine.h"

class World : public QObject
{
	Q_OBJECT
public:
	World(World const&) = delete;
	void operator=(World const&) = delete;
	static ElementEngine* newEngine(QObject* parent = nullptr);
	static void init(QSizeF const& size);
	static Ground* ground();
private:
	Ground* m_ground;
	World(QSizeF const& size);
	void reset(QSizeF const& size);
	static World& instance(QSizeF const& size = QSizeF());
	ElementEngine* createEngine(QObject* parent = nullptr) const;
};

#endif // WORLD_H
