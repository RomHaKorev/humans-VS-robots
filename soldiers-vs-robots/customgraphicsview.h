#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H

#include <QGraphicsView>

class CustomGraphicsView : public QGraphicsView
{
  Q_OBJECT
public:
  CustomGraphicsView(QWidget* parent = nullptr);

protected:
  int currentZoom;
  virtual void wheelEvent(QWheelEvent* event) override;

  virtual void drawForeground(QPainter* painter, const QRectF& rect);

  void scalePainterFontSizeToFit(QPainter* painter, float heightToFitIn);

  virtual void contextMenuEvent(QContextMenuEvent* event);

  QAction* action_show_text_;
};

#endif  // CUSTOMGRAPHICSVIEW_H
