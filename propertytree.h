#ifndef PROPERTYTREE_H
#define PROPERTYTREE_H
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include "boundary.h"


class PropertyTree
{
public:
    PropertyTree();
    PropertyTree(QTreeWidget *widget);
    ~PropertyTree();

public:
    QTreeWidget *parentwidget;
    QTreeWidgetItem* boundary;
    QTreeWidgetItem* boundary_visibleVolume;
    QTreeWidgetItem* boundary_unvisibleVolume;

    QTreeWidgetItem* camera;
    QTreeWidgetItem* laser;
    QTreeWidgetItem* particle;

    bool isVisibleVolumeData = false;
    Boundary bd;


};

#endif // PROPERTYTREE_H
