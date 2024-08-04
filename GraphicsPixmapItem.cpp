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

void GraphicsPixmapItem::SetFitSceneScale(qreal fitSceneScale)
{
    m_fitSceneScale = fitSceneScale;
}

void GraphicsPixmapItem::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    const double scaleStep = 0.01; // 每次滚动事件的缩放增量值  
    auto scale = this->scale();
    qreal new_scale = (event->delta() > 0) ? (scale + scaleStep) : (scale - scaleStep);
    setScale(new_scale);



    //const double scaleStep = 0.1; // 每次滚动事件的缩放增量值  

    //// 获取鼠标相对于图形项的局部位置  
    //QPointF itemPos = event->pos();

    //// 获取当前变换矩阵  
    //QTransform currentTransform = this->transform();

    //// 记录缩放前鼠标相对于场景的位置  
    //QPointF scenePosBefore = mapToScene(itemPos);

    //// 计算缩放因子  
    //qreal factor = (event->delta() > 0) ? (1 + scaleStep) : (1 - scaleStep);

    //// 更新变换矩阵
    //currentTransform.translate(itemPos.x(), itemPos.y());
    //currentTransform.scale(factor, factor);
    //currentTransform.translate(-itemPos.x(), -itemPos.y());
    //setTransform(currentTransform);

    //// 记录缩放后鼠标相对于场景的位置  
    //QPointF scenePosAfter = mapToScene(itemPos);

    //// 计算位移以保持图像点在鼠标位置  
    //QPointF offset = scenePosBefore - scenePosAfter;

    //// 调整图形项的位置  
    //moveBy(offset.x(), offset.y());

    ////qDebug() << "GraphicsPixmapItem::wheelEvent: scale=" << scale();

    QGraphicsPixmapItem::wheelEvent(event);
}

void GraphicsPixmapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_dragStartPos = event->scenePos();

    QGraphicsPixmapItem::mousePressEvent(event);
}

void GraphicsPixmapItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    setPos(pos() + event->scenePos() - m_dragStartPos);
    m_dragStartPos = event->scenePos();

    QGraphicsPixmapItem::mouseMoveEvent(event);
}

void GraphicsPixmapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseReleaseEvent(event);
}
