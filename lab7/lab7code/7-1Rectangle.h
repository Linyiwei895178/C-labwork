#include "Point.h"
class Rectangle {
public:
	Rectangle(float a, float b, float w, float h) : p(a, b), w(w), h(h) {}
	float getX() {
		return p.getX();
	}
	float getY() {
		return p.getY();
	}
	float getW() const {
		return w;
	}
	float getH() const {
		return h;
	}
	void move(float offX, float offY) {
		p.move(offX, offY);
	}
private:
	Point p; // 组合：矩形"包含"点
	float w, h;
};
