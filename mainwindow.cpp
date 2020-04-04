#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Filesystem treeView Initalize
    dirModel = new QFileSystemModel;
    dirModel->setRootPath("");
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    ui->treeViewFileExplorer->setModel(dirModel);
    ui->treeViewFileExplorer->setColumnWidth(0, 800);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeViewFileExplorer_clicked(const QModelIndex &index)
{
    if(fileModel == NULL){
        //Project File treeView Initalize
        fileModel = new QFileSystemModel(this);
        fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
        QStringList filters;
        filters << "*.spimprj";
        fileModel->setNameFilters(filters);
        fileModel->setNameFilterDisables(false);
        fileModel->setRootPath("");
        ui->listViewFileExplorer->setModel(fileModel);
    }

    QString mPath = dirModel->fileInfo(index).absoluteFilePath();
    ui->listViewFileExplorer->setRootIndex(fileModel->setRootPath(mPath));
}

void MainWindow::on_newprojectpushButton_pressed()
{
    QString fileName = QFileDialog::getSaveFileName(this,"New Project",QDir::currentPath(),"SPIM Project (*.spimprj");
    if(!fileName.isEmpty()){
        if(propertytree != NULL)delete propertytree;
        propertytree = new PropertyTree(ui->propertytreeWidget);
        ui->propertytreeWidget->setHeaderLabel(QFileInfo(fileName).fileName());
    }
}

void MainWindow::on_propertytreeWidget_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if(item->text(column) == "VisibleVolume"){
        BoundaryVolumeSettingForm* dlg;
        if(propertytree->isVisibleVolumeData)dlg = new BoundaryVolumeSettingForm(propertytree->vbd);
        else                                 dlg = new BoundaryVolumeSettingForm(true);
        if(dlg->exec() == QDialog::Accepted){//Ok
            propertytree->vbd = dlg->bd;
            propertytree->isVisibleVolumeData = true;
            propertytree->boundary_visibleVolume->setTextColor(0,QColor(78,192,78));
        }
        delete dlg;
    }
    else if(item->text(column) == "unVisibleVolume"){
        BoundaryVolumeSettingForm* dlg;
        if(propertytree->isunVisibleVolumeData)dlg = new BoundaryVolumeSettingForm(propertytree->unvbd);
        else                                 dlg = new BoundaryVolumeSettingForm(false);
        if(dlg->exec() == QDialog::Accepted){//Ok
            propertytree->unvbd = dlg->bd;
            propertytree->isunVisibleVolumeData = true;
            propertytree->boundary_unvisibleVolume->setTextColor(0,QColor(78,192,78));
        }
        delete dlg;
    }
}

void MainWindow::on_addcamerapushButton_pressed()
{
    propertytree->makeNewCamera();
}
