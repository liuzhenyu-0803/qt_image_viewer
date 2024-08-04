#pragma once

#include "GraphicsScene.h"
#include "Define.h"

#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    GraphicsView(QWidget *parent = Q_NULLPTR);
    ~GraphicsView();

    void Initialize();

    void SetImagePath(const QString &imagePath);

    void SetOperation(Operation operation);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void FitPixmapItemInView();

private:
    GraphicsScene *scene = nullptr;
};

