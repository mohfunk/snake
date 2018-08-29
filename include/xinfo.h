#ifndef xinfo_hpp
#define xinfo_hpp

#include<X11/Xlib.h>
#include<X11/Xutil.h>
#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<unistd.h>

struct XInfo {
  Display *display;
  int screen;
  Window window;
  GC gc[3];
  int width;
  int height;
  int bdepth;
  Pixmap buffer;
  bool useBuffer;
};


void initX(int argc, char *argv[], XInfo &xInfo);

#endif
