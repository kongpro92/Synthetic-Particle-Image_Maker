#ifndef BOUNDARYVISIBLEVOLUMESETTINGFORM_H
#define BOUNDARYVISIBLEVOLUMESETTINGFORM_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class BoundaryVisibleVolumeSettingForm;
}

class BoundaryVisibleVolumeSettingForm : public QDialog
{
    Q_OBJECT

public:
    explicit BoundaryVisibleVolumeSettingForm(QWidget *parent = nullptr);
    ~BoundaryVisibleVolumeSettingForm();

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
    float minx;
    float miny;
    float minz;
    float maxx;
    float maxy;
    float maxz;

    void BoundarySet();

private:
    Ui::BoundaryVisibleVolumeSettingForm *ui;
};

#endif // BOUNDARYVISIBLEVOLUMESETTINGFORM_H
