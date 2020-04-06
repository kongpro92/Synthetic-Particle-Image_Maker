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


     Visiblelistclear();
     unVisiblelistclear();
     Cameralistclear();

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

 void PropertyTree::SetBoundaryDataTreeview()
 {
     Visiblelistclear();
     unVisiblelistclear();
     for(int i = 0; i<6; i++){
         QTreeWidgetItem *treeItem = new QTreeWidgetItem(boundary_visibleVolume);
         QString tmp;
         switch(i)
         {
         case 0: tmp.sprintf("minX: %5.3f",vbd.minx); break;
         case 1: tmp.sprintf("minY: %5.3f",vbd.miny); break;
         case 2: tmp.sprintf("minZ: %5.3f",vbd.minz); break;
         case 3: tmp.sprintf("maxX: %5.3f",vbd.maxx); break;
         case 4: tmp.sprintf("maxY: %5.3f",vbd.maxy); break;
         case 5: tmp.sprintf("maxZ: %5.3f",vbd.maxz); break;
         }
         visiblelist.push_back(treeItem);
         treeItem->setText(0, tmp);
         boundary_visibleVolume->addChild(treeItem);
     }

     for(int i = 0; i<6; i++){
         QTreeWidgetItem *treeItem = new QTreeWidgetItem(boundary_unvisibleVolume);
         QString tmp;
         switch(i)
         {
         case 0: tmp.sprintf("minX: %5.3f",unvbd.minx); break;
         case 1: tmp.sprintf("minY: %5.3f",unvbd.miny); break;
         case 2: tmp.sprintf("minZ: %5.3f",unvbd.minz); break;
         case 3: tmp.sprintf("maxX: %5.3f",unvbd.maxx); break;
         case 4: tmp.sprintf("maxY: %5.3f",unvbd.maxy); break;
         case 5: tmp.sprintf("maxZ: %5.3f",unvbd.maxz); break;
         }
         unvisiblelist.push_back(treeItem);
         treeItem->setText(0, tmp);
         boundary_unvisibleVolume->addChild(treeItem);
     }


 }

 void PropertyTree::Visiblelistclear()
 {
     for(int i = 0; i<visiblelist.size();i++){
         delete visiblelist[i];
     }
     visiblelist.clear();
 }

 void PropertyTree::unVisiblelistclear()
 {
     for(int i = 0; i<unvisiblelist.size();i++){
         delete unvisiblelist[i];
     }
     unvisiblelist.clear();
 }

 void PropertyTree::Cameralistclear()
 {
     for(int i = 0; i<cameralist.size();i++){
         delete cameralist[i];
     }
     cameralist.clear();
 }
