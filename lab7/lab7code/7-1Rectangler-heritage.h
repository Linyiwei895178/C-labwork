// 正确Rectangle.h
#include "Point.h"
class Rectangle: public Point {
public:
	// 初始化列表初始化基类，而非创建临时对象
	Rectangle(float a, float b, float w, float h) : Point(a, b) {
		this->w = w;
		this->h = h;
		cout << getX() << ", " << getY() << endl;
	}
	float getH() const {
		return h;
	}
	float getW() const {
		return w;
	}
private:
	float w, h;
};
