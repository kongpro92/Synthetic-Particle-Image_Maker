#include "boundary.h"

Boundary::Boundary()
{

}

Boundary::Boundary(float min_x, float min_y, float min_z, float max_x, float max_y, float max_z, bool visible_)
    :minx(min_x),miny(min_y),minz(min_z),maxx(max_x),maxy(max_y),maxz(max_z),visible(visible_)
{

}
