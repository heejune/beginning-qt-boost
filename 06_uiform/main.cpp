

#include <QApplication>
#include "loginwidget.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    LoginWidget* dialog = new LoginWidget;
    dialog->show();

    return a.exec();
}
