#include"../include/renderer.h"

void Renderer::insertToDis(Displayable* dis) {
    d.push_front(dis);
}
void Renderer::repaint(XInfo &xinfo, bool debug) {
    std::list<Displayable *>::const_iterator begin = d.begin();
    std::list<Displayable *>::const_iterator end = d.end();

    XClearWindow( xinfo.display, xinfo.window );

    if (debug == true) {
        for (int c = 10; c < 800; c += 10) { XDrawLine(xinfo.display, xinfo.window, xinfo.gc[0], c, 0, c, 600); }
        for (int r = 10; r < 600; r += 10) { XDrawLine(xinfo.display, xinfo.window, xinfo.gc[0], 0, r, 800, r); }
    }
    XWindowAttributes windowInfo;
    XGetWindowAttributes(xinfo.display, xinfo.window, &windowInfo);
    unsigned int height = windowInfo.height;
    unsigned int width = windowInfo.width;


    while( begin != end ) {
        Displayable *dis = *begin;
        dis->paint(xinfo);
        begin++;
    }

    XFlush( xinfo.display );
}
