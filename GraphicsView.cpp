#include "GraphicsView.h"

#include <QResizeEvent>

#include <QDebug>
#include <QTimer>

GraphicsView::GraphicsView(QWidget *parent) 
    : QGraphicsView(parent)
{
    
}

GraphicsView::~GraphicsView()
{

}

void GraphicsView::Initialize()
{
    if (!scene)
    {
        scene = new GraphicsScene(this);
    }
    setScene(scene);
    
    scene->Initialize();
}

void GraphicsView::SetImagePath(const QString &imagePath)
{
    if (scene)
    {
        scene->SetImagePath(imagePath);

        FitPixmapItemInView();
    }
}

void GraphicsView::SetOperation(Operation operation)
{
    if (scene)
    {
        scene->SetOperation(operation);
    }
}

void GraphicsView::FitPixmapItemInView()
{
    if (auto pixmapItem = scene->GetPixmapItem())
    {
        auto pixmap = pixmapItem->pixmap();
        if (pixmap.width() > viewport()->width() || pixmap.height() > viewport()->height())
        {
            fitInView(pixmapItem, Qt::KeepAspectRatio);
        }
        else
        {
            resetTransform();
        }
    }
}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    FitPixmapItemInView();

    QGraphicsView::resizeEvent(event);
}