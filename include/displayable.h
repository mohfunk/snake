#ifndef displayable_hpp
#define displayable_hpp


#include "xinfo.h"


class Displayable {
public:
	Displayable(int x, int y) : x(x), y(y) {}
	~Displayable() {}
	virtual void paint(XInfo &xinfo) = 0;
	int getX() { return x;}
	int getY() { return y;} 
	void setX(int nx) { x = nx;}
	void setY(int ny) { y = ny;}
protected:
	int x;
	int y;
};

#endif
