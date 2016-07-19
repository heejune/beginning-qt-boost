#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "asioclient.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_getBtn_clicked();
    void on_success(const QString& msg);

private:
    Ui::Widget *ui;
    AsioClient* client;
};

#endif // WIDGET_H
