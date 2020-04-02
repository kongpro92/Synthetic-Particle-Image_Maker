#include "boundaryvolumesettingform.h"
#include "ui_boundaryvolumesettingform.h"

BoundaryVolumeSettingForm::BoundaryVolumeSettingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoundaryVolumeSettingForm)
{
    ui->setupUi(this);

    QSettings settings("Kongpro","SPIM",this);
    ui->minXlineEdit->setText(settings.value("minX","").toString());
    ui->minYlineEdit->setText(settings.value("minY","").toString());
    ui->minZlineEdit->setText(settings.value("minZ","").toString());
    ui->maxXlineEdit->setText(settings.value("maxX","").toString());
    ui->maxYlineEdit->setText(settings.value("maxY","").toString());
    ui->maxZlineEdit->setText(settings.value("maxZ","").toString());
    BoundarySet();
}

BoundaryVolumeSettingForm::BoundaryVolumeSettingForm(Boundary b,QWidget *parent):
    QDialog(parent),
    ui(new Ui::BoundaryVolumeSettingForm)
{
    ui->setupUi(this);

    ui->minXlineEdit->setText(QString::number(b.minx));
    ui->minYlineEdit->setText(QString::number(b.miny));
    ui->minZlineEdit->setText(QString::number(b.minz));
    ui->maxXlineEdit->setText(QString::number(b.maxx));
    ui->maxYlineEdit->setText(QString::number(b.maxy));
    ui->maxZlineEdit->setText(QString::number(b.maxz));
    BoundarySet();
}

BoundaryVolumeSettingForm::~BoundaryVolumeSettingForm()
{
    delete ui;
}




void BoundaryVolumeSettingForm::on_OkpushButton_pressed()
{
    QSettings settings("Kongpro","SPIM",this);
    settings.setValue("minX",ui->minXlineEdit->text());
    settings.setValue("minY",ui->minYlineEdit->text());
    settings.setValue("minZ",ui->minZlineEdit->text());
    settings.setValue("maxX",ui->maxXlineEdit->text());
    settings.setValue("maxY",ui->maxYlineEdit->text());
    settings.setValue("maxZ",ui->maxZlineEdit->text());
    accept();
}

void BoundaryVolumeSettingForm::on_CancelpushButton_pressed()
{
    reject();
}


void BoundaryVolumeSettingForm::BoundarySet()
{
    bd.minx = ui->minXlineEdit->text().toFloat();
    bd.miny = ui->minYlineEdit->text().toFloat();
    bd.minz = ui->minZlineEdit->text().toFloat();
    bd.maxx = ui->maxXlineEdit->text().toFloat();
    bd.maxy = ui->maxYlineEdit->text().toFloat();
    bd.maxz = ui->maxZlineEdit->text().toFloat();

    using namespace cv;
    Mat img = Mat(350,350,CV_8UC3,Scalar(0,0,0));
    QPixmap pixmap =  QPixmap::fromImage(QImage((unsigned char*) img.data,img.cols,img.rows,img.step,QImage::Format_RGB888));
    ui->Imagelabel->setPixmap( pixmap );
    // opencv 로 블록 그려 넣기 imagelabel에
}
