#ifndef gamemanager_hpp
#define gamemanager_hpp

#include <list>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "displayable.h"
#include "snake.h"
#include "fruit.h"
#include "global.h"
#include "mainloop.h"

enum State {
    _SPLASH = 0,
    _GAME = 1,
    _PAUSE = 2,
    _GAMEOVER = 3,
    _DEBUG = 4,
};
class Snake;
class GameManager {
    friend class MainLoop;
    Snake* s;
    Fruit* f;
    int score;
    public:
    State cs;
    GameManager();
    ~GameManager();
    void pause() { cs = _PAUSE; }
    void resume() { cs = _GAME; }
    void restart();
    void checkColl();
    void handleKeyPress(XInfo &xinfo, XEvent &event);
    void handleAnimation(XInfo &info, int inside);
};



#endif
