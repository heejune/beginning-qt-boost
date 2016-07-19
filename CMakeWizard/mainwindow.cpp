#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include "cmakelists.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->flagsTable->horizontalHeader()->setStretchLastSection(true);
    ui->flagsTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->sourcesTable->horizontalHeader()->setStretchLastSection(true);
    ui->sourcesTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(currentTabChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InsertFlagItem(const QString & key, const QString & value)
{
    int row = ui->flagsTable->rowCount();
    ui->flagsTable->insertRow(row);

    auto keyColumn = new QTableWidgetItem(key);
    auto valueColumn = new QTableWidgetItem(value);

    ui->flagsTable->setItem(row, 0, keyColumn);
    ui->flagsTable->setItem(row, 1, valueColumn);
}

void MainWindow::insertNewIncludeDirectory(const QString & dir)
{
    QListWidgetItem* newItem = new QListWidgetItem(dir);
    newItem->setFlags(newItem->flags() | Qt::ItemIsEditable);

    ui->includeList->addItem(newItem);
}

void MainWindow::addSource(const QString & target, const QString& sources)
{
    int row = ui->sourcesTable->rowCount();
    ui->sourcesTable->insertRow(row);

    auto targetColumn = new QTableWidgetItem(target);
    auto sourcesColumn = new QTableWidgetItem(sources);

    ui->sourcesTable->setItem(row, 0, targetColumn);
    ui->sourcesTable->setItem(row, 1, sourcesColumn);
}

void MainWindow::on_actionExport_triggered()
{
    QString dir = QFileDialog::getExistingDirectory(this,
                                      "Directory to save", QDir::currentPath(), QFileDialog::ShowDirsOnly);

    if (dir.length() == 0) {
        QMessageBox::critical(this,
                              "Failed to get dir", "Failed to get directory to save", QMessageBox::Ok);
        return;
    }

    auto filePath = QDir(dir).filePath("CMakeLists.txt");

    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
        return;

    QTextStream stream(&file);

    PrepareCMakeListsVariables();

    stream << cmakeListsResult << endl;

    file.close();
}

void MainWindow::on_flagsAddBtn_clicked()
{
    InsertFlagItem("<Key>", "<Value>");
}

void MainWindow::on_flagsRemoveBtn_clicked()
{
    ui->flagsTable->removeRow(ui->flagsTable->currentRow());
}

void MainWindow::on_addIncludeBtn_clicked()
{
    insertNewIncludeDirectory("<Path>");
}

void MainWindow::on_includeList_itemChanged(QListWidgetItem *item)
{
    if (item->text().length() == 0) {
        ui->includeList->takeItem(ui->includeList->row(item));
    }
}

void MainWindow::on_addSourceBtn_clicked()
{
    addSource("<Target>", "main.cpp");
}

void MainWindow::on_removeSourceBtn_clicked()
{
    ui->sourcesTable->removeRow(ui->sourcesTable->currentRow());
}

void MainWindow::currentTabChanged(int index)
{
    qDebug() << "current tab index " << index << endl;

    // preview tab selected
    if (index == 4) {
        //
        PrepareCMakeListsVariables();
    }
}

void MainWindow::PrepareCMakeListsVariables()
{
    CMakeLists  cmakelists;

    // project tab
    QString projectName = ui->projectNameEdit->text();

    cmakelists.SetProjectName(projectName);

    // flags tab
    auto flagsCount = ui->flagsTable->rowCount();
    for (int rowIndex = 0; rowIndex < flagsCount ; rowIndex++) {
        auto keyItem = ui->flagsTable->item(rowIndex, 0);
        auto valueItem = ui->flagsTable->item(rowIndex, 1);

        // QString, QString
        QString flagKey = keyItem->text();
        QString flagValue = valueItem->text();
        cmakelists.AddCMakeFlags(flagKey, flagValue);
    }

    // preprocessor tab
    if (ui->definesEdit->toPlainText().size() > 0) {
        QStringList defines = ui->definesEdit->toPlainText().split(QRegExp("\\ |\\;|\\n"));

        for (int index = 0;index < defines.length();index++) {
            qDebug() << defines.at(index) << endl;
            cmakelists.AddDefine(defines.at(index));
        }
    }

    // directory tab
    // 1. include dir (QListWidget)
    for (int row = 0; row <ui->includeList->count();row++) {
        auto item = ui->includeList->item(row);// QListWidgetItem
        //QString includeDir = item->text();
        cmakelists.AddIncludeDirectory(item->text());
    }
    // 2. sources (QTableWidget)
    for (int row = 0; row<ui->sourcesTable->rowCount();row++) {
        auto target = ui->sourcesTable->item(row, 0);
        auto sources = ui->sourcesTable->item(row, 1);
        // target, source files
        cmakelists.AddSource(target->text(), sources->text());
    }

    // preview tab
    QString previewCMakeLists_txt = cmakelists.GenerateCMakeLists();

    ui->previewEdit->clear();
    ui->previewEdit->appendPlainText(previewCMakeLists_txt);

    cmakeListsResult = previewCMakeLists_txt;
}
