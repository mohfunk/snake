#ifndef renderer_hpp
#define renderer_hpp

#include<list>
#include"displayable.h"
#include"xinfo.h"
#include"global.h"
class Renderer {
    std::list<Displayable* > d;
    public:
    void insertToDis(Displayable* dis);
    void repaint(XInfo &xinfo, bool debug);
};

#endif
