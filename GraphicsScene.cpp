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
    connect(this, &GraphicsScene::sceneRectChanged, this, [this](const QRectF &rect) {

        // 加个信号阻塞，防止下面两句又触发sceneRectChanged信号，导致死循环
        QSignalBlocker blocker(this);

        setPixmapItemToSceneCenter();
        scalePixmapItemToFitScene();
    });
}

void GraphicsScene::SetImagePath(const QString &imagePath)
{
    if (!m_pixmapItem)
    {
        m_pixmapItem = new GraphicsPixmapItem();
        addItem(m_pixmapItem);
    }

    m_pixmapItem->setPixmap(QPixmap(imagePath));
    setPixmapItemToSceneCenter();
    scalePixmapItemToFitScene();
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

void GraphicsScene::setPixmapItemToSceneCenter()
{
    if (!m_pixmapItem)
    {
        return;
    }

    m_pixmapItem->setPos(sceneRect().center() - m_pixmapItem->pixmap().rect().center());
}

void GraphicsScene::scalePixmapItemToFitScene()
{
    if (!m_pixmapItem)
    {
        return;
    }

    QSizeF pixmapSize = m_pixmapItem->pixmap().size();
    auto pixmapSizeScaled = pixmapSize.scaled(width(), height(), Qt::KeepAspectRatio);

    m_pixmapItem->setTransformOriginPoint(m_pixmapItem->boundingRect().center());
    m_pixmapItem->setScale(pixmapSizeScaled.width() / pixmapSize.width());
    m_pixmapItem->SetFitSceneScale(m_pixmapItem->scale());
}