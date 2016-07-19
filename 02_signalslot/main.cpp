#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

    QPushButton button("Close");

    QObject::connect(&button, SIGNAL(clicked(bool)), &app, SLOT(quit()));

    button.show();

    return app.exec();
}
