#ifndef global_hpp
#define global_hpp

#include <sys/time.h>
#include <iostream>
#include <math.h>
const int Border = 1;
const int BufferSize = 10;
const int FPS = 30;
const int width = 800;
const int height = 600;
void error( std::string str);
unsigned long now();
int distance(int a, int b);
#endif
