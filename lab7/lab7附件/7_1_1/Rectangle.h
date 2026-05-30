//Rectangle.h
#ifndef _RECTANGLE_H
#define _RECTANGLE_H
#include "Point.h"

class Rectangle: public Point {	
public:	
	initRectangle(float a, float b, float w, float h) {
		Point(a, b); 
		cout << getX() <<", "<< getY() <<endl;	
		
		this->w = w;
		this->h = h;
	}
	float getH() const { return h; }
	float getW() const { return w; }
private:	
	float w, h;
};

#endif //_RECTANGLE_H
