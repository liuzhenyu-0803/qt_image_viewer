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

        //FitPixmapItemInView();

        /*QTimer::singleShot(10, this, [this](){
            qDebug() << "GraphicsView::SetImagePath" << scene->GetPixmapItem()->boundingRect();
            FitPixmapItemInView();
        });*/
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
        fitInView(pixmapItem, Qt::KeepAspectRatio);
    }
}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    if (scene)
    {
        scene->setSceneRect(viewport()->rect());
    }

    //FitPixmapItemInView();

    QGraphicsView::resizeEvent(event);
}