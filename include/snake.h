#ifndef snake_hpp
#define snake_hpp

#include"xinfo.h"
#include"displayable.h"
#include"gamemanager.h"
#include<list>
#include"fruit.h"

class SnakeChain : public Displayable {
    public:
        int dirX;
        int dirY;
        SnakeChain(int ix, int iy, int idirX, int idirY) : Displayable(ix,iy), dirX(idirX), dirY(idirY) {}
        virtual void paint(XInfo &xinfo) {}
};
class Snake : public Displayable {
    friend class GameManager;
    private:
    const int blockSize;
    int directionX;
    int directionY;
    std::list<SnakeChain* > sbody;
    bool inv;
    bool hit;
    public:
    int velocity;
    int length;
    Snake(int ix, int iy, int vel) 
        : Displayable(ix,iy),
        blockSize(10),
        velocity(vel),
        length(0),
        directionX(0),
        directionY(0),
        inv(false),
        hit(false)
    {

    }
    ~Snake() { sbody.clear(); }
    virtual void paint(XInfo &xinfo);
    void move();
    void changeDirX(int dir) { directionX = dir; directionY = 0; }
    void changeDirY(int dir) { directionY = dir; directionX = 0; }
    void changeVel(int vel) { velocity = vel; }
    bool selfColl() { return hit; }
    void setCol() { hit = false; }
};


#endif
