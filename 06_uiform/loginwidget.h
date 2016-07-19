#include <QWidget>
#include "ui_loginwidget.h"

class LoginWidget : public QWidget, public Ui::loginWidget {
    Q_OBJECT
public:
    explicit LoginWidget(QWidget* parent = nullptr);
};
