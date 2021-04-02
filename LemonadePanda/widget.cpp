#include "widget.h"

#include <QHBoxLayout>
#include <QLabel>


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    setStyleSheet( "QWidget{ background-color : rgba( 160, 160, 160, 255); border-radius : 7px;  }" );
    QLabel *label = new QLabel(this);
    QHBoxLayout *layout = new QHBoxLayout();
    label->setText("This is our Zork, yes thats it we're done.");
    layout->addWidget(label);
    setLayout(layout);


    QPixmap bg("/Users/Wiki/Desktop/folders/anime pictures/shhh totally drawing ideas/cutie.jpg");
    bg  = bg.scaled(this -> size(), Qt::IgnoreAspectRatio);
    QPalette pal;
    pal.setBrush(QPalette::Background, bg);
    this->setPalette(pal);
}
