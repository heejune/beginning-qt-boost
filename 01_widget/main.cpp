#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

    QPushButton button("Hello World!");

    button.show();

    return app.exec();
}
