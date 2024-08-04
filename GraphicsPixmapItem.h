#pragma once

#include <QGraphicsPixmapItem>

class GraphicsPixmapItem :
    public QGraphicsPixmapItem
{
public:
    GraphicsPixmapItem(QGraphicsItem *parent = 0);
    ~GraphicsPixmapItem();

protected:
    void wheelEvent(QGraphicsSceneWheelEvent *event);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
};

