#ifndef BOUNDARY_H
#define BOUNDARY_H


class Boundary
{
public:
    Boundary();
    Boundary(float min_x, float min_y, float min_z, float max_x, float max_y, float max_z, bool visible_);


    float minx;
    float miny;
    float minz;
    float maxx;
    float maxy;
    float maxz;
    bool  visible;
};

#endif // BOUNDARY_H
