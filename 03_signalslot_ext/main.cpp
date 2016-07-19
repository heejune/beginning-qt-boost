#include <QApplication>
#include <QSlider>
#include <QSpinBox>
#include <QHBoxLayout>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QWidget* window = new QWidget;
    QSpinBox* spinBox = new QSpinBox;
    QSlider* slider = new QSlider(Qt::Horizontal);

    spinBox->setRange(0, 100);
    slider->setRange(0, 100);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);

    window->setLayout(layout);
    window->show();

    return a.exec();
}
