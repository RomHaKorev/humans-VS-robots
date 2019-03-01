//#ifndef GAMEWORLD_H
#if 0
#define GAMEWORLD_H

#include <QGraphicsView>

#include "model/ground.h"
#include "elements/grounditem.h"
#include "elements/hero.h"

class GameWorld : public QGraphicsView
{
	Q_OBJECT
public:
	explicit GameWorld(QWidget *parent = nullptr);
private:
	QGraphicsScene* scene;
	Ground* ground;
	GroundItem* groundItem;
	Hero* hero;

	//virtual void mousePressEvent(QMouseEvent *event) override;
	//virtual void mouseReleaseEvent(QMouseEvent *event) override;

public slots:
	void move();
	void stop();
};

#endif // GAMEWORLD_H
