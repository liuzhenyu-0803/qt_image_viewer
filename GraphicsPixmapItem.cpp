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
    const double scaleStep = 0.01; // ÿ�ι����¼�����������ֵ  
    auto scale = this->scale();
    qreal new_scale = (event->delta() > 0) ? (scale + scaleStep) : (scale - scaleStep);
    setScale(new_scale);



    //const double scaleStep = 0.1; // ÿ�ι����¼�����������ֵ  

    //// ��ȡ��������ͼ����ľֲ�λ��  
    //QPointF itemPos = event->pos();

    //// ��ȡ��ǰ�任����  
    //QTransform currentTransform = this->transform();

    //// ��¼����ǰ�������ڳ�����λ��  
    //QPointF scenePosBefore = mapToScene(itemPos);

    //// ������������  
    //qreal factor = (event->delta() > 0) ? (1 + scaleStep) : (1 - scaleStep);

    //// ���±任����
    //currentTransform.translate(itemPos.x(), itemPos.y());
    //currentTransform.scale(factor, factor);
    //currentTransform.translate(-itemPos.x(), -itemPos.y());
    //setTransform(currentTransform);

    //// ��¼���ź��������ڳ�����λ��  
    //QPointF scenePosAfter = mapToScene(itemPos);

    //// ����λ���Ա���ͼ��������λ��  
    //QPointF offset = scenePosBefore - scenePosAfter;

    //// ����ͼ�����λ��  
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
