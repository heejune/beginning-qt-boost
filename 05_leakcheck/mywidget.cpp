#include "mywidget.h"
#include <QDebug>
#include <QHBoxLayout>

mywidget::mywidget(QWidget *parent) : QWidget(parent)
{
    qDebug() << "mywidget constructor called " << endl;

    button = new QPushButton;

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(button);

    setLayout(layout);
}


mywidget::~mywidget() {
    qDebug() << "mywidget destructor called " << endl;
}
