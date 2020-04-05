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

    bool isData =false;
    Boundary vbd = {0,0,0,0,0,0};
    Boundary unvbd = {0,0,0,0,0,0};

    deque<QTreeWidgetItem*> cameralist;

    void makeNewCamera();
};

#endif // PROPERTYTREE_H
