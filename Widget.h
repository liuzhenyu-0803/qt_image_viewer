#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"

#include "GraphicsView.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::WidgetClass ui;
    GraphicsView *view = nullptr;
    QList<QString> image_path_list_;
};
