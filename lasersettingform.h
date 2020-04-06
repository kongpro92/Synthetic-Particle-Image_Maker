#ifndef LASERSETTINGFORM_H
#define LASERSETTINGFORM_H

#include <QDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

namespace Ui {
class LaserSettingForm;
}

class LaserSettingForm : public QDialog
{
    Q_OBJECT

public:
    explicit LaserSettingForm(QWidget *parent = nullptr);
    ~LaserSettingForm();

    QChart *chart = new QChart();

public:
    QLineSeries *Intensityseries = NULL;
    void DrawLaserIntensityChart();
    int s;
    float I;
private:
    Ui::LaserSettingForm *ui;
};

#endif // LASERSETTINGFORM_H
