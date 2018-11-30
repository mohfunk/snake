#include "xinfo.h"
#include "global.h"


void initX(int argc, char *argv[], XInfo &xInfo) {

    XSizeHints hints;
    unsigned long white, black;


    xInfo.display = XOpenDisplay( "" );

    if ( !xInfo.display ) {
        error("cant open display");
    }
    xInfo.screen = DefaultScreen( xInfo.display );
    white = XWhitePixel( xInfo.display, xInfo.screen );
    black = XBlackPixel( xInfo.display, xInfo.screen );

    hints.x = 100;
    hints.y = 100;
    hints.width = 800;
    hints.height = 600;
    hints.flags = PPosition | PSize;

    xInfo.window = XCreateSimpleWindow(
            xInfo.display,
            DefaultRootWindow( xInfo.display ),
            hints.x, hints.y,
            hints.width, hints.height,
            Border,
            white,
            black);


    XSetStandardProperties(
            xInfo.display,
            xInfo.window,
            "SNAKE",
            "Animate",
            None,
            argv, argc,
            &hints );

    /*
     * Create Graphics Contexts
     */
    int i = 0;


    xInfo.screen = DefaultScreen( xInfo.display );
    xInfo.gc[i] = XCreateGC(xInfo.display, xInfo.window, 0, 0);
    xInfo.bdepth = DefaultDepth(xInfo.display, xInfo.screen);
    xInfo.buffer = XCreatePixmap(xInfo.display, xInfo.window, width, height, xInfo.bdepth);
    xInfo.useBuffer = true;
    XSetForeground(xInfo.display, xInfo.gc[i], WhitePixel(xInfo.display, xInfo.screen));
    XSetBackground(xInfo.display, xInfo.gc[i], BlackPixel(xInfo.display, xInfo.screen));
    XSetFillStyle(xInfo.display, xInfo.gc[i], FillSolid);
    XSetLineAttributes(xInfo.display, xInfo.gc[i],
            1, LineSolid, CapButt, JoinRound);
    XFontStruct * font;
    font = XLoadQueryFont (xInfo.display, "12x24");
    XSetFont (xInfo.display, xInfo.gc[i], font->fid);


    XSelectInput(xInfo.display, xInfo.window,
            ButtonPressMask | KeyPressMask |
            PointerMotionMask |
            EnterWindowMask | LeaveWindowMask |
            StructureNotifyMask);  // for resize events

    /*
     * Put the window on the screen.
     *
     */
    XMapRaised( xInfo.display, xInfo.window );
    XFlush(xInfo.display);
}
