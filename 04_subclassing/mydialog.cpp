
#include "mydialog.h"
#include <QMessageBox>
#include <QCloseEvent>
#include <QLineEdit>
#include <QVBoxLayout>

MyDialog::MyDialog(QWidget* parent):QDialog(parent) {
    lineEdit = new QLineEdit;

    connect(lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(myTextChanged(const QString&)));

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(lineEdit);

    setLayout(layout);
}

void MyDialog::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton yesno = QMessageBox::question(this, "title", "yes or no", QMessageBox::Yes | QMessageBox::No);

    if (yesno == QMessageBox::Yes) {
        event->accept();
    } else if (yesno == QMessageBox::No) {
        event->ignore();
    }
}

void MyDialog::myTextChanged(const QString& text) {
    if (text == "qt5") {
        // void onKeywordMatched(const QString&);
        emit onKeywordMatched(text);
    }
}
