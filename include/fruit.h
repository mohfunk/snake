#ifndef fruit_hpp
#define fruit_hpp

#include"xinfo.h"
#include"displayable.h"
#include"global.h"
class Fruit: public Displayable {

    public:
        Fruit(int x, int y) : Displayable(x,y) {}
        ~Fruit() {}
        virtual void paint(XInfo &xinfo) {
            XFillRectangle(xinfo.display, xinfo.window, xinfo.gc[0], x, y, 10,10);
        }
};



#endif
