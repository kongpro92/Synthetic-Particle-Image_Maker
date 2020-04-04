#ifndef PROPERTYTREE_H
#define PROPERTYTREE_H
#include <QTreeWidgetItem>
#include <QTreeWidget>
#include "boundary.h"
#include <deque>

using namespace std;

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
    bool isunVisibleVolumeData = false;
    Boundary vbd = {0,0,0,0,0,0,true};
    Boundary unvbd = {};

    deque<QTreeWidgetItem*> cameralist;

    void makeNewCamera();
};

#endif // PROPERTYTREE_H
