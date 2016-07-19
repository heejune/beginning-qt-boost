#include "widget.h"
#include "ui_widget.h"
#include <QRegularExpression>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    client(new AsioClient)
{
    ui->setupUi(this);

    ui->paramTable->setColumnCount(2);
    ui->paramTable->setHorizontalHeaderLabels(QString("key;value").split(";"));
    ui->paramTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->urlEdit->setText("http://127.0.0.1:5000/");

    connect(client, SIGNAL(read_finish(QString)), this, SLOT(on_success(QString)));
}

Widget::~Widget()
{
    delete ui;
    delete client;
}

void Widget::on_getBtn_clicked()
{
    QString url = ui->urlEdit->text();
    //client->Get("127.0.0.1", "/");

    QRegularExpression re("^(?:([A-Za-z]+):)?(\\/{0,3})([0-9.\\-A-Za-z]+)(?::(\\d+))?(?:\\/([^?#]*))?(?:\\?([^#]*))?(?:#(.*))?$");

    QRegularExpressionMatch match = re.match(url);

    if (match.hasMatch()) {
        auto hostName = match.captured(3);
        auto urlPath = "/" + match.captured(5);

        client->Get(hostName, urlPath);
    }
}

void Widget::on_success(const QString &msg)
{
    ui->responseEdit->setText(msg);
}
