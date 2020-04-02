#include "propertytree.h"

PropertyTree::PropertyTree()
{

}

 PropertyTree::PropertyTree(QTreeWidget *widget)
 {
     parentwidget = widget;
     Boundary = new QTreeWidgetItem(widget);
     Boundary->setText(0,"Boundary Condition");
     Boundary_VisibleVolume = new QTreeWidgetItem(Boundary);
     Boundary_VisibleVolume->setText(0,"VisibleVolume");
     Boundary_VisibleVolume->setTextColor(0,QColor(255,0,0));
     Boundary_unVisibleVolume = new QTreeWidgetItem(Boundary);
     Boundary_unVisibleVolume->setText(0,"unVisibleVolume");
     Boundary_unVisibleVolume->setTextColor(0,QColor(255,0,0));

     Camera= new QTreeWidgetItem(widget);
     Camera->setText(0,"Camera Condition");

     Laser= new QTreeWidgetItem(widget);
     Laser->setText(0,"Laser Condition");

     Particle= new QTreeWidgetItem(widget);
     Particle->setText(0,"Particle Condition");
 }


 PropertyTree::~PropertyTree()
 {
     Boundary->removeChild(Boundary_VisibleVolume);
     Boundary->removeChild(Boundary_unVisibleVolume);

     parentwidget->removeItemWidget(Boundary,0);
     parentwidget->removeItemWidget(Camera,0);
     parentwidget->removeItemWidget(Laser,0);
     parentwidget->removeItemWidget(Particle,0);

     delete Boundary;
     delete Boundary_VisibleVolume;
     delete Boundary_unVisibleVolume;

     delete Camera;
     delete Laser;
     delete Particle;
 }
