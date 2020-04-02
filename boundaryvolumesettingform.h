#ifndef BOUNDARYVISIBLEVOLUMESETTINGFORM_H
#define BOUNDARYVISIBLEVOLUMESETTINGFORM_H

#include <QDialog>
#include <QSettings>
#include <QPixmap>
#include "boundary.h"
#include "opencv2/opencv.hpp"


namespace Ui {
class BoundaryVolumeSettingForm;
}

class BoundaryVolumeSettingForm : public QDialog
{
    Q_OBJECT

public:
    explicit BoundaryVolumeSettingForm(QWidget *parent = nullptr);
    explicit BoundaryVolumeSettingForm(Boundary b,QWidget *parent = nullptr);
    ~BoundaryVolumeSettingForm();

private slots:
    void on_OkpushButton_pressed();
    void on_CancelpushButton_pressed();

    void on_minXlineEdit_returnPressed(){BoundarySet();}
    void on_minYlineEdit_returnPressed(){BoundarySet();}
    void on_minZlineEdit_returnPressed(){BoundarySet();}
    void on_maxXlineEdit_returnPressed(){BoundarySet();}
    void on_maxYlineEdit_returnPressed(){BoundarySet();}
    void on_maxZlineEdit_returnPressed(){BoundarySet();}

public:
    Boundary bd;

    void BoundarySet();

private:
    Ui::BoundaryVolumeSettingForm *ui;
};

#endif // BOUNDARYVISIBLEVOLUMESETTINGFORM_H
