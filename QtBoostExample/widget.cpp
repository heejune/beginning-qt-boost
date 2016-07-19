#include "widget.h"
#include "ui_widget.h"
#include <boost/thread.hpp>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    boost::thread worker([](){
        boost::posix_time::seconds sleep_time(3);
        boost::this_thread::sleep(sleep_time);

        qDebug() << "thread about to be finished!" << endl;
    });

    worker.join();
}
