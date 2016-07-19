#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

//class QListWidgetItem;
QT_FORWARD_DECLARE_CLASS(QListWidgetItem);

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void InsertFlagItem(const QString&, const QString&);
    void insertNewIncludeDirectory(const QString&);
    void addSource(const QString&, const QString& sources);

    void PrepareCMakeListsVariables();

private slots:
    void on_actionExport_triggered();

    void on_flagsAddBtn_clicked();

    void on_flagsRemoveBtn_clicked();

    void on_addIncludeBtn_clicked();

    void on_includeList_itemChanged(QListWidgetItem *item);

    void on_addSourceBtn_clicked();

    void on_removeSourceBtn_clicked();

    void currentTabChanged(int index);

private:
    Ui::MainWindow *ui;
    QString cmakeListsResult;
};

#endif // MAINWINDOW_H
