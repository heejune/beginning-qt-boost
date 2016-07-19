#include <QCoreApplication>
#include <QDebug>

int main(int argc, char* argv[]) {

    QCoreApplication a(argc, argv);

    qDebug() << "It's running!" << endl;

    return a.exec();
}
