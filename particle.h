#ifndef PARTICLE_H
#define PARTICLE_H
#include <random>

using namespace std;

struct postion
{
    double x,y,z;
};

struct boundary
{
    double minx,miny,minz,maxx,maxy,maxz;
};

class Particle
{
public:
    Particle();

private:
    postion pos = {0,0,0};


    void SetPosX(double x){this->pos.x = x;}
    void SetPosY(double y){this->pos.y = y;}
    void SetPosZ(double z){this->pos.z = z;}

public:
    static Particle MakeRandomPositionParticle(boundary b);

};

#endif // PARTICLE_H
