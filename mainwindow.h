#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include "opencv2/opencv.hpp"
#include <QCommandLineParser>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QTreeWidgetItem>
#include "propertytree.h"
#include <QFileInfo>
#include <QMessageBox>
#include <QSettings>
#include "boundaryvolumesettingform.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_treeViewFileExplorer_clicked(const QModelIndex &index);



    void on_newprojectpushButton_pressed();
    void on_propertytreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel = NULL;
    PropertyTree *propertytree = NULL;
};


#endif // MAINWINDOW_H

