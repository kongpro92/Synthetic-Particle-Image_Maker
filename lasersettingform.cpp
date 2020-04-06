#include "lasersettingform.h"
#include "ui_lasersettingform.h"

LaserSettingForm::LaserSettingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaserSettingForm)
{
    ui->setupUi(this);



    ui->s1radioButton->setChecked(true);
I = 100;
s=2;
DrawLaserIntensityChart();
}

LaserSettingForm::~LaserSettingForm()
{
    delete ui;
}

void LaserSettingForm::DrawLaserIntensityChart()
{
    if(Intensityseries!=NULL)delete Intensityseries;
    Intensityseries = new QLineSeries();
    for(float i = -2;i<=2;i+=0.04){
        Intensityseries->append(i,I*exp(-0.39894228*pow(abs(2*i*i),s)));
        // *Intensityseries << QPointF(i, exp(-0.67*pow(abs(2*i*i),s)));
    }
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(Intensityseries);
    chart->setTitle("Intensity Profile");

    QValueAxis *axisX = new QValueAxis();
     axisX->setTitleText("Z/Z0");
     axisX->setLabelFormat("%i");
     axisX->setTickCount(-1);
     chart->addAxis(axisX, Qt::AlignBottom);
     Intensityseries->attachAxis(axisX);

     QValueAxis *axisY = new QValueAxis();
     axisY->setTitleText("I/I0");
     axisY->setLabelFormat("%4.0f");
     axisY->setTickCount(4);
     axisY->setMax(I*1.5);
     chart->addAxis(axisY, Qt::AlignLeft);
     Intensityseries->attachAxis(axisY);



    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->gridLayout->addWidget(chartView);

}
