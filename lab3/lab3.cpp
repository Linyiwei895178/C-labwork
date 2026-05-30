//#include <iostream>
//#include <cmath>
//using namespace std;
//
//class Point {
//public:
//	Point(int xx = 0, int yy = 0) {
//		x = xx;
//		y = yy;
//	}
//	Point(Point &p);
//	int getX();
//	int getY();
//
//	~Point() {
//		cout << "this is the deconstructor of Point" << endl;
//	}
//private:
//	int x;
//	int y;
//
//};
//
//int Point::getX() {
//	return x;
//}
//
//int Point::getY() {
//	return y;
//}
//
//Point::Point(Point &p) {
//	x = p.x;
//	y = p.y;
//	cout << "Calling the copy constructor of Point" << endl;
//}
//
//class Line {
//public:
//	Line(Point xp1, Point xp2);
//	Line(Line &l);
//	double getLen() {
//		return len;
//	}
//
//	~Line() {
//		cout << "this is the deconstructor of Line" << endl;
//	}
//private:
//	Point p1, p2;
//	double len;
//};
//
//
//Line::Line(Point xp1, Point xp2) : p1(xp1), p2(xp2) {
//	cout << "Calling constructor of Line" << endl;
//	double x = static_cast<double>(p1.getX() - p2.getX());
//	double y = static_cast<double>(p1.getY() - p2.getY());
//	len = sqrt(x * x + y * y);
//}
//
//Line::Line(Line &l): p1(l.p1), p2(l.p2) {
//	cout << "Calling the copy constructor of Line" << endl;
//	len = l.len;
//}
//
//void test1() {
//	Point p1(6, 6);
//	Point p2(8, 8);
//	Line l1(p1, p2);
//	cout << "the len of the line is " << l1.getLen() << endl;
//}
//
//int main() {
//	test1();
//	return 0;
//}



//银行账户管理系统
#include <iostream>
#include <string>   // 用于存储姓名
using namespace std;

// 银行账户类（课本核心：封装性）
class BankAccount {
// 私有成员：数据隐藏，外部无法直接访问
private:
	string id;     // 账号
	string name;   // 户主姓名
	double balance;// 账户余额

// 公有成员函数：对外提供操作接口（课本核心：公有接口访问私有数据）
public:
	// 1. 构造函数：开户（初始化账户信息）
	BankAccount(string accountId, string userName, double initialMoney) {
		id = accountId;
		name = userName;
		// 初始存款不能为负数
		if (initialMoney >= 0) {
			balance = initialMoney;
		} else {
			balance = 0;
			cout << "初始金额无效，已自动设置为0元" << endl;
		}
	}

	// 2. 存款函数：传入存款金额
	void deposit(double money) {
		if (money > 0) {
			balance += money;
			cout << "存款成功！当前余额：" << balance << "元" << endl;
		} else {
			cout << "存款金额无效！" << endl;
		}
	}

	// 3. 取款函数：传入取款金额，校验余额
	void withdraw(double money) {
		if (money <= 0) {
			cout << "取款金额无效！" << endl;
		} else if (money > balance) {
			cout << "余额不足，取款失败！" << endl;
		} else {
			balance -= money;
			cout << "取款成功！当前余额：" << balance << "元" << endl;
		}
	}

	// 4. 查询余额
	double getBalance() {
		return balance;
	}

	// 5. 显示账户完整信息
	void showInfo() {
		cout << "-------------------------" << endl;
		cout << "账户信息：" << endl;
		cout << "账号：" << id << endl;
		cout << "户主：" << name << endl;
		cout << "余额：" << balance << "元" << endl;
		cout << "-------------------------" << endl;
	}
};

// 主函数：测试账户功能（课本要求：对象的创建与使用）
int main() {
	// 1. 开户：创建账户对象（账号、姓名、初始存款）
	BankAccount account("202500130002", "LYW", 666.0);
	cout << "开户成功！" << endl;
	account.showInfo();  // 显示初始信息

	// 2. 存款操作
	account.deposit(500);

	// 3. 取款操作
	account.withdraw(300);

	// 4. 测试：超额取款（校验功能）
	account.withdraw(2000);

	// 5. 最终查询账户信息
	account.showInfo();

	return 0;
}
