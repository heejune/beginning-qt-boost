#include <QApplication>
#include "mydialog.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    MyDialog* dialog = new MyDialog;
    //MyDialog dialog;

    QObject::connect(dialog, SIGNAL(onKeywordMatched(const QString&)),
                     &app, SLOT(quit()));

    dialog->show();

    return app.exec();
}
