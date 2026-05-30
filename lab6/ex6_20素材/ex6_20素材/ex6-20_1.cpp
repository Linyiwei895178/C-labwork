//对应实验六，1.(2) ；相对_0 增加了=操作符重载验证
#include <iostream>
using namespace std;

class SimpleCircle
{
public:
	SimpleCircle();
	SimpleCircle(int);
	SimpleCircle(const SimpleCircle &);
	~SimpleCircle() { 
		delete itsRadius;
		}
	void setRadius(int);
	int getRadius() const;
	SimpleCircle operator=(SimpleCircle &a){
		cout<<"in operator ="<<endl;
		//此处应该完成深拷贝 
	}
	
private:
	int *itsRadius;
};

SimpleCircle::SimpleCircle()
{
	itsRadius = new int(5);
}

SimpleCircle::SimpleCircle(int radius)
{
	itsRadius = new int(radius);
}

SimpleCircle::SimpleCircle(const SimpleCircle & rhs)
{	cout<<"in copy constructor "<<endl;
	int val = rhs.getRadius();
	itsRadius = new int(val);
}

int SimpleCircle::getRadius() const
{
	return *itsRadius;
}

int main()
{
	SimpleCircle  CircleOne(7),CircleTwo(8); 
	SimpleCircle CircleThree=CircleOne;  //在定义处，调用复制构造函数，非操作符重载 
	CircleThree=CircleTwo; //此处调用操作符重载 ,所以在操作符重载函数中需要对带指针的对象深复制 
	
	cout << "CircleOne: " << CircleOne.getRadius() << endl;
	cout << "CircleTwo: " << CircleTwo.getRadius() << endl;
	cout << "CircleThree: " << CircleThree.getRadius() << endl;
	return 0;
}
