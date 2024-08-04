#include "GraphicsScene.h"

#include "GraphicsRectItem.h"

#include <QGraphicsSceneMouseEvent>
#include <QApplication>

#include <QDebug>
#include <QGraphicsPixmapItem>

GraphicsScene::GraphicsScene(QObject *parent)
    : QGraphicsScene(parent)
{

}

GraphicsScene::~GraphicsScene()
{
}

void GraphicsScene::Initialize()
{

}

void GraphicsScene::SetImagePath(const QString &imagePath)
{
    if (!m_pixmapItem)
    {
        m_pixmapItem = new GraphicsPixmapItem();
        addItem(m_pixmapItem);
    }

    QPixmap pixmap(imagePath);
    m_pixmapItem->setPixmap(pixmap);
    m_pixmapItem->boundingRect();
    setSceneRect(pixmap.rect());
}

QGraphicsPixmapItem *GraphicsScene::GetPixmapItem() const
{
    return m_pixmapItem;
}

void GraphicsScene::SetOperation(Operation operation)
{
    m_operation = operation;
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_startPos = event->scenePos();

    QGraphicsScene::mousePressEvent(event);

    qDebug() << "mousePressEvent" << m_pixmapItem->boundingRect();
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    auto currentPos = event->scenePos();

    if (m_operation == Operation::None)
    {

    }
    else
    {
        if (!m_drawingItem && (currentPos - m_startPos).manhattanLength() > QApplication::startDragDistance())
        {
            auto rectItem = new GraphicsRectItem();
            rectItem->setBrush(Qt::red);
            addItem(rectItem);

            m_drawingItem = rectItem;
        }

        if (m_drawingItem)
        {
            if (auto item = qgraphicsitem_cast<GraphicsRectItem *>(m_drawingItem))
            {
                auto rect = QRectF(m_startPos, currentPos);
                auto normaizedRect = rect.normalized();
                item->setRect(normaizedRect);
            }
        }
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_drawingItem = nullptr;

    QGraphicsScene::mouseReleaseEvent(event);
}