//同名隐藏，虚函数可多态 
#include<iostream>
using namespace std;

class Base {
public:
   void show() {
        cout << "Base show()" << endl;
    }
    void show(int i) { //普通成员函数重载 
        cout << "Base show(int)" << endl;
    }
   virtual void fun() const { //virtual函数
        cout << "Base fun()"<<  endl;
    }
   virtual void fun(double r1,double r2,double r3) const { //virtual函数
        cout << "Base fun r1:"<<r1<<" r2:"<<r2<<" r3:"<<r3<<endl;
    }
    virtual void fun(int a,int b=2) const { //virtual函数重载,但参数缺省值属于静态编译 
        cout << "Base a:"<<a <<" b:"<<b <<endl;
    }
};
 
class Derived : public Base {
public:
    void show() { // 隐藏了基类的一切同名函数, 忽略参数 ；规则36 不重定义非virtual函数。避免用基类与子类指针是表现不同，违反不变性。 
        cout << "Derived show()" << endl;
    }
    virtual void fun() const{  
    	cout << "Derived fun()"<< endl; 
	}
	virtual void fun(int a,int b=3) const { //virtual函数重载,规则37：不重定义继承来的缺省参数
        cout << "Derived fun a:"<<a <<" b:"<<b <<endl;
    }
};
 
int main() {
    Base b;
	Derived d;
     
    //对象应用 
    b.show(); 
    b.show(1);
    b.fun();   
    b.fun(5,6); 
    
    d.show(); // 输出?
    //d.show(1);// 为什不可以？
	d.Base::show(1);  //为什么可以？
    d.fun(); //是多态吗？
    //d.fun(5,6,7); //为什么virtual函数也不可以？ 
    
	b=d;    //子对象转父对象，隐式转换 
	b.show(); //多态吗？ 
    b.show(1); //为什么可以？ 
    b.fun();  //多态吗？
    b.fun(5,6); //为什么可以？
	
	//d=static_case<Base>b; //父转子，为什么用static_cast也不行？怎样才能完成转换？ 

    cout<<"-------------"<<endl;
    //指针应用 
    Derived* pd=&d;
    pd->show();  //多态吗？同名隐藏吗？ 
    //pd->show(7); //为什么不行？  
    pd->fun();  //多态吗？
    //pd->fun(1.1,2.2,3.5); //为什么不可以？
	pd->fun(8); // b为什么是3？ 
		
    Base* pb = &d; //子类对象指针赋给父类指针 ，父指子     
    pb->show();  //多态吗？ 
    pb->show(7); //多态吗？解释输出。
    pb->fun();  //多态吗？ 
    pb->fun(1.1,2.2,3.5); //为什么可以？ 
	pb->fun(8); // b为什么不是3？
    
    return 0;
}
