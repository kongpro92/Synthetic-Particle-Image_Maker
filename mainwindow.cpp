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

}

void MainWindow::on_addcamerapushButton_pressed()
{
    propertytree->makeNewCamera();
}

void MainWindow::on_setpropertypushButton_pressed()
{
    if(propertytree == NULL)return;
    if(ui->propertytreeWidget->isItemSelected(propertytree->boundary))
    {
        BoundaryVolumeSettingForm* dlg;
        if(propertytree->isData)dlg = new BoundaryVolumeSettingForm(propertytree->vbd,
                                                                                 propertytree->unvbd);
        else                                 dlg = new BoundaryVolumeSettingForm();
        if(dlg->exec() == QDialog::Accepted){//Ok
            propertytree->vbd = dlg->bd;
            propertytree->unvbd = dlg->bd2;
            propertytree->isData = true;
            propertytree->boundary->setTextColor(0,QColor(0,0,255));
            propertytree->SetBoundaryDataTreeview();


        }
        delete dlg;
    }
    else if(ui->propertytreeWidget->isItemSelected(propertytree->laser)){
        LaserSettingForm* dlg;
        dlg = new LaserSettingForm();
        dlg->exec();
    }
}
