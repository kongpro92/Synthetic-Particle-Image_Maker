#include "propertytree.h"

PropertyTree::PropertyTree()
{

}

 PropertyTree::PropertyTree(QTreeWidget *widget)
 {
     parentwidget = widget;
     boundary = new QTreeWidgetItem(widget);
     boundary->setText(0,"Boundary Condition");
     boundary->setTextColor(0,QColor(255,0,0));
     boundary_visibleVolume = new QTreeWidgetItem(boundary);
     boundary_visibleVolume->setText(0,"VisibleVolume");
     boundary_unvisibleVolume = new QTreeWidgetItem(boundary);
     boundary_unvisibleVolume->setText(0,"unVisibleVolume");


     camera= new QTreeWidgetItem(widget);
     camera->setText(0,"Camera Condition");
     camera->setTextColor(0,QColor(255,0,0));
     laser= new QTreeWidgetItem(widget);
     laser->setText(0,"Laser Condition");
     laser->setTextColor(0,QColor(255,0,0));
     particle= new QTreeWidgetItem(widget);
     particle->setText(0,"Particle Condition");
     particle->setTextColor(0,QColor(255,0,0));
 }


 PropertyTree::~PropertyTree()
 {
     boundary->removeChild(boundary_visibleVolume);
     boundary->removeChild(boundary_unvisibleVolume);

     parentwidget->removeItemWidget(boundary,0);
     parentwidget->removeItemWidget(camera,0);
     parentwidget->removeItemWidget(laser,0);
     parentwidget->removeItemWidget(particle,0);

     delete boundary;
     delete boundary_visibleVolume;
     delete boundary_unvisibleVolume;

     delete camera;
     delete laser;
     delete particle;
 }

 void PropertyTree::makeNewCamera()
 {
     QTreeWidgetItem* newcamera = new QTreeWidgetItem(camera);
     cameralist.push_back(newcamera);
     QString str = "camera" + QString::number(cameralist.size());
     newcamera->setText(0,str);
     newcamera->setTextColor(0,QColor(255,0,0));
 }
