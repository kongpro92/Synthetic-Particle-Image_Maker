#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    dirModel = new QFileSystemModel;
    dirModel->setRootPath("");
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    ui->treeViewFileExplorer->setModel(dirModel);

    // FILES

        fileModel = new QFileSystemModel(this);

        // Set filter
        fileModel->setFilter(QDir::NoDotAndDotDot |
                            QDir::Files);

        QStringList filters;
        filters << "*.spimprj";
        fileModel->setNameFilters(filters);
        fileModel->setNameFilterDisables(false);
        // QFileSystemModel requires root path
        fileModel->setRootPath("");

        // Attach the file model to the view
        ui->listViewFileExplorer->setModel(fileModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treeViewFileExplorer_clicked(const QModelIndex &index)
{
    QString mPath = dirModel->fileInfo(index).absoluteFilePath();
        ui->listViewFileExplorer->setRootIndex(fileModel->setRootPath(mPath));
}

void MainWindow::on_newprojectpushButton_pressed()
{
    QString fileName = QFileDialog::getSaveFileName(this,"New Project",QDir::currentPath(),"SPIM Project (*.spimprj");
    if(!fileName.isEmpty()){
        //프로젝트 파일 생성!
        //QSettings 이용해서 레지스트리 등록
    }
}
