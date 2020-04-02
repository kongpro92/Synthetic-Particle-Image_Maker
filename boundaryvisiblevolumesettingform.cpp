#include "boundaryvisiblevolumesettingform.h"
#include "ui_boundaryvisiblevolumesettingform.h"

BoundaryVisibleVolumeSettingForm::BoundaryVisibleVolumeSettingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoundaryVisibleVolumeSettingForm)
{
    ui->setupUi(this);

    QSettings settings("Kongpro","SPIM",this);
    ui->minXlineEdit->setText(settings.value("minX","").toString());
    ui->minYlineEdit->setText(settings.value("minY","").toString());
    ui->minZlineEdit->setText(settings.value("minZ","").toString());
    ui->maxXlineEdit->setText(settings.value("maxX","").toString());
    ui->maxYlineEdit->setText(settings.value("maxY","").toString());
    ui->maxZlineEdit->setText(settings.value("maxZ","").toString());
    minx = settings.value("minX","").toFloat();
    miny = settings.value("minY","").toFloat();
    minz = settings.value("minZ","").toFloat();
    maxx = settings.value("minX","").toFloat();
    maxy = settings.value("maxY","").toFloat();
    maxz = settings.value("maxZ","").toFloat();

}

BoundaryVisibleVolumeSettingForm::~BoundaryVisibleVolumeSettingForm()
{
    delete ui;
}




void BoundaryVisibleVolumeSettingForm::on_OkpushButton_pressed()
{

}

void BoundaryVisibleVolumeSettingForm::on_CancelpushButton_pressed()
{

}


void BoundaryVisibleVolumeSettingForm::BoundarySet()
{
    minx = ui->minXlineEdit->text().toFloat();
    miny = ui->minYlineEdit->text().toFloat();
    minz = ui->minZlineEdit->text().toFloat();
    maxx = ui->maxXlineEdit->text().toFloat();
    maxy = ui->maxYlineEdit->text().toFloat();
    maxz = ui->maxZlineEdit->text().toFloat();

    // opencv 로 블록 그려 넣기 imagelabel에
}
