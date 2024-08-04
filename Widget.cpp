#include "Widget.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    {
        auto view_frame_layout = new QVBoxLayout(ui.view_frame_);
        view = new GraphicsView(this);
        view_frame_layout->addWidget(view);
    }

    {
        auto buttons_frame_layout = new QHBoxLayout(ui.buttons_frame_);

        auto previousButton = new QPushButton("Previous", this);
        buttons_frame_layout->addWidget(previousButton);

        auto nextButton = new QPushButton("Next", this);
        buttons_frame_layout->addWidget(nextButton);

        auto arrowButton = new QPushButton("Arrow", this);
        arrowButton->setCheckable(true);
        buttons_frame_layout->addWidget(arrowButton);

        auto rectButton = new QPushButton("Rect", this);
        rectButton->setCheckable(true);
        buttons_frame_layout->addWidget(rectButton);

        connect(previousButton, &QPushButton::clicked, this, [=]() {
            view->SetImagePath(image_path_list_.at(0));
        });

        connect(nextButton, &QPushButton::clicked, this, [=]() {
            view->SetImagePath(image_path_list_.at(1));
        });
    }

    view->Initialize();

    image_path_list_ << ":/image1.png" << ":/image2.png";
    view->SetImagePath(image_path_list_.at(0));
}

Widget::~Widget()
{
}
