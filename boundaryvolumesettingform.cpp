#include "boundaryvolumesettingform.h"
#include "ui_boundaryvolumesettingform.h"

BoundaryVolumeSettingForm::BoundaryVolumeSettingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoundaryVolumeSettingForm)
{
    ui->setupUi(this);
    QSettings settings("Kongpro","SPIM",this);
    ui->minXlineEdit->setText(settings.value("vsminX","").toString());
    ui->minYlineEdit->setText(settings.value("vsminY","").toString());
    ui->minZlineEdit->setText(settings.value("vsminZ","").toString());
    ui->maxXlineEdit->setText(settings.value("vsmaxX","").toString());
    ui->maxYlineEdit->setText(settings.value("vsmaxY","").toString());
    ui->maxZlineEdit->setText(settings.value("vsmaxZ","").toString());


    QSettings settings2("Kongpro","SPIM",this);
    ui->minXlineEdit_2->setText(settings2.value("unvsminX","").toString());
    ui->minYlineEdit_2->setText(settings2.value("unvsminY","").toString());
    ui->minZlineEdit_2->setText(settings2.value("unvsminZ","").toString());
    ui->maxXlineEdit_2->setText(settings2.value("unvsmaxX","").toString());
    ui->maxYlineEdit_2->setText(settings2.value("unvsmaxY","").toString());
    ui->maxZlineEdit_2->setText(settings2.value("unvsmaxZ","").toString());



BoundarySet();
}



BoundaryVolumeSettingForm::BoundaryVolumeSettingForm(Boundary b,Boundary unb, QWidget *parent):
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

    ui->minXlineEdit_2->setText(QString::number(unb.minx));
    ui->minYlineEdit_2->setText(QString::number(unb.miny));
    ui->minZlineEdit_2->setText(QString::number(unb.minz));
    ui->maxXlineEdit_2->setText(QString::number(unb.maxx));
    ui->maxYlineEdit_2->setText(QString::number(unb.maxy));
    ui->maxZlineEdit_2->setText(QString::number(unb.maxz));

    BoundarySet();
}

BoundaryVolumeSettingForm::~BoundaryVolumeSettingForm()
{
    delete ui;
}

void BoundaryVolumeSettingForm::BoundarySet()
{
    bd.minx = ui->minXlineEdit->text().toFloat();
    bd.miny = ui->minYlineEdit->text().toFloat();
    bd.minz = ui->minZlineEdit->text().toFloat();
    bd.maxx = ui->maxXlineEdit->text().toFloat();
    bd.maxy = ui->maxYlineEdit->text().toFloat();
    bd.maxz = ui->maxZlineEdit->text().toFloat();

    bd2.minx = ui->minXlineEdit_2->text().toFloat();
    bd2.miny = ui->minYlineEdit_2->text().toFloat();
    bd2.minz = ui->minZlineEdit_2->text().toFloat();
    bd2.maxx = ui->maxXlineEdit_2->text().toFloat();
    bd2.maxy = ui->maxYlineEdit_2->text().toFloat();
    bd2.maxz = ui->maxZlineEdit_2->text().toFloat();
}

void BoundaryVolumeSettingForm::on_OkpushButton_pressed()
{
    QSettings settings("Kongpro","SPIM",this);
    settings.setValue("vsminX",ui->minXlineEdit->text());
    settings.setValue("vsminY",ui->minYlineEdit->text());
    settings.setValue("vsminZ",ui->minZlineEdit->text());
    settings.setValue("vsmaxX",ui->maxXlineEdit->text());
    settings.setValue("vsmaxY",ui->maxYlineEdit->text());
    settings.setValue("vsmaxZ",ui->maxZlineEdit->text());
    settings.setValue("unvsminX",ui->minXlineEdit_2->text());
    settings.setValue("unvsminY",ui->minYlineEdit_2->text());
    settings.setValue("unvsminZ",ui->minZlineEdit_2->text());
    settings.setValue("unvsmaxX",ui->maxXlineEdit_2->text());
    settings.setValue("unvsmaxY",ui->maxYlineEdit_2->text());
    settings.setValue("unvsmaxZ",ui->maxZlineEdit_2->text());


    BoundarySet();
    accept();
}

void BoundaryVolumeSettingForm::on_CancelpushButton_pressed()
{
    reject();
}
