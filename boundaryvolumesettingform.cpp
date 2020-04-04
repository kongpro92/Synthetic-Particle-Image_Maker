#include "boundaryvolumesettingform.h"
#include "ui_boundaryvolumesettingform.h"

BoundaryVolumeSettingForm::BoundaryVolumeSettingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoundaryVolumeSettingForm)
{
    ui->setupUi(this);
}

BoundaryVolumeSettingForm::BoundaryVolumeSettingForm(bool visible, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoundaryVolumeSettingForm)
{
    ui->setupUi(this);

    if(visible){
        QSettings settings("Kongpro","SPIM",this);
        ui->minXlineEdit->setText(settings.value("vsminX","").toString());
        ui->minYlineEdit->setText(settings.value("vsminY","").toString());
        ui->minZlineEdit->setText(settings.value("vsminZ","").toString());
        ui->maxXlineEdit->setText(settings.value("vsmaxX","").toString());
        ui->maxYlineEdit->setText(settings.value("vsmaxY","").toString());
        ui->maxZlineEdit->setText(settings.value("vsmaxZ","").toString());
        bd.visible = true;
    }
    else{
        QSettings settings("Kongpro","SPIM",this);
        ui->minXlineEdit->setText(settings.value("unvsminX","").toString());
        ui->minYlineEdit->setText(settings.value("unvsminY","").toString());
        ui->minZlineEdit->setText(settings.value("unvsminZ","").toString());
        ui->maxXlineEdit->setText(settings.value("unvsmaxX","").toString());
        ui->maxYlineEdit->setText(settings.value("unvsmaxY","").toString());
        ui->maxZlineEdit->setText(settings.value("unvsmaxZ","").toString());
        bd.visible = false;
    }

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
    if(bd.visible){
        QSettings settings("Kongpro","SPIM",this);
        settings.setValue("vsminX",ui->minXlineEdit->text());
        settings.setValue("vsminY",ui->minYlineEdit->text());
        settings.setValue("vsminZ",ui->minZlineEdit->text());
        settings.setValue("vsmaxX",ui->maxXlineEdit->text());
        settings.setValue("vsmaxY",ui->maxYlineEdit->text());
        settings.setValue("vsmaxZ",ui->maxZlineEdit->text());
    }
    else{
        QSettings settings("Kongpro","SPIM",this);
        settings.setValue("unvsminX",ui->minXlineEdit->text());
        settings.setValue("unvsminY",ui->minYlineEdit->text());
        settings.setValue("unvsminZ",ui->minZlineEdit->text());
        settings.setValue("unvsmaxX",ui->maxXlineEdit->text());
        settings.setValue("unvsmaxY",ui->maxYlineEdit->text());
        settings.setValue("unvsmaxZ",ui->maxZlineEdit->text());
    }

    BoundarySet();
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
}
