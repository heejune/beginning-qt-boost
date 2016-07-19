
#include <QDialog>
#include <QString>

class QLineEdit;

class MyDialog : public QDialog {
    Q_OBJECT
public:
    explicit MyDialog(QWidget* parent = nullptr);

    QLineEdit* lineEdit;

    void closeEvent(QCloseEvent *event);

signals:
    void onKeywordMatched(const QString&);

private slots:
    void myTextChanged(const QString&);
};
