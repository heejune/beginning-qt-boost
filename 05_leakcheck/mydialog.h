
#include <QDialog>
#include <QString>
#include "mywidget.h"

class QLineEdit;

class MyDialog : public QDialog {
    Q_OBJECT
public:
    explicit MyDialog(QWidget* parent = nullptr);
    virtual ~MyDialog();

    QLineEdit* lineEdit;
    mywidget* widget;

    void closeEvent(QCloseEvent *event);

signals:
    void onKeywordMatched(const QString&);

private slots:
    void myTextChanged(const QString&);
};
