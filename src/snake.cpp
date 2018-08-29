#include "../include/snake.h"
#include "../include/global.h"
#include <math.h>

void Snake::paint(XInfo &xinfo) {
    XFillRectangle(xinfo.display, xinfo.window, xinfo.gc[0], x, y, blockSize, blockSize);
    SnakeChain* sbl;
    int sbx;
    int sby;
    for(std::list<SnakeChain *>::iterator sb=sbody.begin(); sb != sbody.end(); ++sb) {
        sbl = *sb;
        sbx = sbl->getX();
        sby = sbl->getY();
        if (sbx == x && sby == y) hit = true;
        XFillRectangle(xinfo.display, xinfo.window, xinfo.gc[0], sbl->getX(), sbl->getY(), blockSize, blockSize);
    }
}
void Snake::move() {
    x = x + (directionX * blockSize);
    y = y + (directionY * blockSize);

    if (x >= width) {
        x = 0;
    } else if ( x <=  -blockSize) {
        x = width; 
    }
    if (y >= height) {
        y = 0;
    } else if ( y <=  -blockSize) {
        y = height;

    }

    if (length != 0) {
        SnakeChain* tail = sbody.back();	
        tail->setX( x - ( directionX * blockSize));
        tail->setY( y - ( directionY * blockSize));
        tail->dirX = directionX;
        tail->dirY = directionY;
        sbody.pop_back();
        sbody.push_front(tail);
    }
}

