#ifndef DATE_H
#define DATE_H
class Date {
private:
    int year, month, day;
    int totalDays;  // 距基准日期的总天数，用于计息
    bool isLeapYear(int y) const;
    int getMonthDays(int y, int m) const;
    void calcTotalDays();
public:
    Date(int y, int m, int d);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getMaxDay() const;
    void show() const;
    int operator-(const Date& other) const; // 计算两个日期相差天数
};
#endif