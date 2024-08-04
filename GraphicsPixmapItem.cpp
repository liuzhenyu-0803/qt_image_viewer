#include "GraphicsPixmapItem.h"

#include <QGraphicsSceneWheelEvent>
#include <QGraphicsSceneMouseEvent>

#include <QDebug>
#include <QGraphicsScene>


GraphicsPixmapItem::GraphicsPixmapItem(QGraphicsItem *parent)
    : QGraphicsPixmapItem(parent)
{
    setFlag(ItemIsSelectable);
}

GraphicsPixmapItem::~GraphicsPixmapItem()
{
}

void GraphicsPixmapItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    QGraphicsPixmapItem::wheelEvent(event);
}

void GraphicsPixmapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mousePressEvent(event);
}

void GraphicsPixmapItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseMoveEvent(event);
}

void GraphicsPixmapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseReleaseEvent(event);
}
