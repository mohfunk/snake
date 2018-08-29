#include"../include/global.h"



void error( std::string str) {
    std::cerr << str << std::endl;
    exit(0);
}

unsigned long now() {
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000 + tv.tv_usec;
}

