#include "propertytree.h"

PropertyTree::PropertyTree()
{

}

 PropertyTree::PropertyTree(QTreeWidget *widget)
 {
     parentwidget = widget;
     boundary = new QTreeWidgetItem(widget);
     boundary->setText(0,"Boundary Condition");
     boundary_visibleVolume = new QTreeWidgetItem(boundary);
     boundary_visibleVolume->setText(0,"VisibleVolume");
     boundary_visibleVolume->setTextColor(0,QColor(255,0,0));
     boundary_unvisibleVolume = new QTreeWidgetItem(boundary);
     boundary_unvisibleVolume->setText(0,"unVisibleVolume");
     boundary_unvisibleVolume->setTextColor(0,QColor(255,0,0));

     camera= new QTreeWidgetItem(widget);
     camera->setText(0,"Camera Condition");

     laser= new QTreeWidgetItem(widget);
     laser->setText(0,"Laser Condition");

     particle= new QTreeWidgetItem(widget);
     particle->setText(0,"Particle Condition");
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
