#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>

class mywidget : public QWidget
{
    Q_OBJECT
public:
    explicit mywidget(QWidget *parent = 0);
    virtual ~mywidget();

    QPushButton* button;

signals:

public slots:
};

#endif // MYWIDGET_H
