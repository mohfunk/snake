#ifndef mainloop_hpp
#define mainloop_hpp

#include <list>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include "displayable.h"
#include "global.h"
#include "xinfo.h"
#include "renderer.h"
#include "gamemanager.h"
class GameManager;
class MainLoop {
  Renderer* rl;
  GameManager* gm;
  XInfo xinfo;
public:
  bool debug;
  MainLoop();
  void mLoop(XInfo &xinfo, int a, int b);
  void tick(int argc, char *argv[] );
};



#endif
