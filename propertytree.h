#ifndef PROPERTYTREE_H
#define PROPERTYTREE_H
#include <QTreeWidgetItem>
#include <QTreeWidget>

class PropertyTree
{
public:
    PropertyTree();
    PropertyTree(QTreeWidget *widget);
    ~PropertyTree();

public:
    QTreeWidget *parentwidget;
    QTreeWidgetItem* Boundary;
    QTreeWidgetItem* Boundary_VisibleVolume;
    QTreeWidgetItem* Boundary_unVisibleVolume;

    QTreeWidgetItem* Camera;
    QTreeWidgetItem* Laser;
    QTreeWidgetItem* Particle;

};

#endif // PROPERTYTREE_H
