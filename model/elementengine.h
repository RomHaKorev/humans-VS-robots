#ifndef ELEMENTENGINE_H
#define ELEMENTENGINE_H

#include <QObject>
#include <QPropertyAnimation>

#include "ground.h"

class ElementEngine : public QObject
{
	Q_OBJECT
	Q_PROPERTY(qreal distance READ distance WRITE setDistance NOTIFY moved)
public:
	explicit ElementEngine(Ground const& ground, QObject *parent = nullptr);
	qreal distance() const;
	void setDistance(qreal);

private:
	Ground const& ground;
	qreal propDistance;
	QPropertyAnimation* animation;
	QPointF position;

signals:
	void moved();

public slots:
	void moveLeft();
	void moveRight();
	void stop();
};

#endif // ELEMENTENGINE_H
