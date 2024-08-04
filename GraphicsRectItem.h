#pragma once

#include <QGraphicsRectItem>

class GraphicsRectItem : public QGraphicsRectItem
{
    //Q_OBJECT

public:
    GraphicsRectItem(QGraphicsItem *parent = nullptr);
    ~GraphicsRectItem();
};

