#include "customgraphicsview.h"

#include <QAction>
#include <QDebug>
#include <QMenu>
#include <QWheelEvent>

#include <math.h>

CustomGraphicsView::CustomGraphicsView(QWidget* parent) : QGraphicsView(parent)
{
  setScene(new QGraphicsScene);
  action_show_text_ = new QAction("Show text");
  action_show_text_->setCheckable(true);
  action_show_text_->setChecked(false);
}

void CustomGraphicsView::drawForeground(QPainter* painter, const QRectF& rect)
{

  // Select scale
  std::vector<double> steps = { 0.1, 0.15, 0.25, 0.5, 1, 2, 5, 10, 15, 25, 50 };
  qDebug() << "Rect: " << rect.topLeft() << "->" << rect.bottomRight();
  int target_y = 10;
  double step0 = (rect.bottom() - rect.top()) / target_y;
  double step = step0;
  double min_d = 1000000;
  for (size_t i = 0; i < steps.size(); i++)
  {
	if (fabs(steps[i] - step0) < min_d)
	{
	  step = steps[i];
	  min_d = fabs(steps[i] - step0);
	}
  }
  qDebug() << "Step: " << step;

  // Bottom right scale bar corner
  QPointF aux = mapToScene(QPoint(10, 10)) - rect.topLeft();
  QPointF br = mapToScene(mapFromScene(rect.bottomRight()) - QPoint(10, 10));

  // Draw outside rectangle
  painter->setPen(QPen(Qt::black, step * 0.01, Qt::SolidLine, Qt::SquareCap));
  painter->drawRect(QRectF(br - QPointF(4 * step, aux.y()), br));

  painter->save();
  painter->resetMatrix();
  painter->drawText(100, 100, "Foobar");
  painter->restore();

  // Draw left half
  painter->fillRect(QRectF(br - QPointF(4 * step, aux.y()), br - QPointF(3 * step, aux.y() / 2)), Qt::black);
  painter->fillRect(QRectF(br - QPointF(4 * step, aux.y() / 2), br - QPointF(3 * step, 0)), Qt::white);

  // Draw right half
  painter->fillRect(QRectF(br - QPointF(3 * step, aux.y()), br - QPointF(2 * step, aux.y() / 2)), Qt::white);
  painter->fillRect(QRectF(br - QPointF(3 * step, aux.y() / 2), br - QPointF(2 * step, 0)), Qt::black);
  painter->fillRect(QRectF(br - QPointF(2 * step, aux.y()), br - QPointF(0, aux.y() / 2)), Qt::black);
  painter->fillRect(QRectF(br - QPointF(2 * step, aux.y() / 2), br), Qt::white);

  // Add texts
  if (action_show_text_->isChecked())
  {
	painter->save();
	QTransform matrix(painter->transform());
	painter->resetMatrix();
	QRectF rect_text(br - QPointF(5 * step, aux.y() * 2.1), br - QPointF(3 * step, aux.y() * 1.1));
	rect_text = matrix.mapRect(rect_text);
	painter->drawText(rect_text, Qt::AlignCenter, QString::number(0));
	painter->restore();

	rect_text = QRectF(br - QPointF(4 * step, aux.y() * 2.1), br - QPointF(2 * step, aux.y() * 1.1));
	rect_text = matrix.mapRect(rect_text);

	painter->drawText(rect_text, Qt::AlignCenter, QString::number(step));
	rect_text = QRectF(br - QPointF(3 * step, aux.y() * 2.1), br - QPointF(1 * step, aux.y() * 1.1));
	rect_text = matrix.mapRect(rect_text);
	painter->drawText(rect_text, Qt::AlignCenter, QString::number(2 * step));
	rect_text = QRectF(br - QPointF(1 * step, aux.y() * 2.1), br - QPointF(-1 * step, aux.y() * 1.1));
	rect_text = matrix.mapRect(rect_text);
	painter->drawText(rect_text, Qt::AlignCenter, QString::number(4 * step));
	painter->restore();
  }
}

void CustomGraphicsView::scalePainterFontSizeToFit(QPainter* painter, float heightToFitIn)
{
  float oldFontSize, newFontSize, oldHeight;
  QFont r_font = painter->font();

  // Init
  oldFontSize = r_font.pointSizeF();

  // Loop
  for (int i = 0; i < 3; i++)
  {
	qDebug() << i << "a";
	oldHeight = painter->fontMetrics().boundingRect('D').height();
	qDebug() << i << "b";
	newFontSize = (heightToFitIn / oldHeight) * oldFontSize;
	qDebug() << i << "c";
	r_font.setPointSizeF(newFontSize);
	qDebug() << i << "d";
	painter->setFont(r_font);
	qDebug() << i << "e";
	oldFontSize = newFontSize;
	qDebug() << "OldFontSize=" << oldFontSize << "HtoFitIn=" << heightToFitIn << "  fontHeight=" << oldHeight
			 << "newFontSize=" << newFontSize;
  }

  // End
  r_font.setPointSizeF(newFontSize);
  painter->setFont(r_font);
}

void CustomGraphicsView::wheelEvent(QWheelEvent* event)
{
  // if ctrl pressed, use original functionality
  if (event->modifiers() & Qt::ControlModifier)
	QGraphicsView::wheelEvent(event);
  // otherwise, do yours
  else
  {
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	if (event->delta() > 0)
	{
	  scale(1.1, 1.1);
	}
	else
	{
	  scale(0.9, 0.9);
	}
  }
}

void CustomGraphicsView::contextMenuEvent(QContextMenuEvent* event)
{
  // Create menu
  QMenu menu(this);

  // Add Fit in view
  menu.addAction(action_show_text_);

  // Exectue menu
  menu.exec(event->globalPos());
}
