#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include "GraphicsPixmapItem.h"
#include "Define.h"

#include <QGraphicsScene>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene(QObject *parent = nullptr);
    ~GraphicsScene();

    void Initialize();

    void SetImagePath(const QString &imagePath);
    QGraphicsPixmapItem *GetPixmapItem() const;

    void SetOperation(Operation operation);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    void setPixmapItemToSceneCenter();
    void scalePixmapItemToFitScene();

private:
    GraphicsPixmapItem *m_pixmapItem = nullptr;

    QPointF m_startPos;
    QList<QGraphicsItem *> m_drawedItems;
    QGraphicsItem *m_drawingItem = nullptr;
    Operation m_operation = Operation::None;
};

#endif // GRAPHICSSCENE_H

