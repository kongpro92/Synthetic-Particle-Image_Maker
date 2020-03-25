#include "particle.h"
#include <iostream>

Particle::Particle()
{

}


Particle Particle::MakeRandomPositionParticle(boundary b)
{
    Particle par;

    ///랜덤 포지션 내용 만들어 넣기
    random_device rd;
    mt19937_64 gen(rd());
    uniform_real_distribution<> randx(b.minx,b.maxx);
    uniform_real_distribution<> randy(b.miny,b.maxy);
    uniform_real_distribution<> randz(b.minz,b.maxz);
    par.SetPosX(randx(gen));
    par.SetPosY(randy(gen));
    par.SetPosZ(randz(gen));

    cout << par.pos.x << "\t" << par.pos.y << "\t" << par.pos.z << endl;

    return par;
}


