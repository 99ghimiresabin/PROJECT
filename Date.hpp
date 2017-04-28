
#ifndef DATE_HPP_
#define DATE_HPP_
#include <iostream>
#include <stdio.h>

using namespace std;

class Date {
private:
    int Year;
    int Month;
    int Day;
    
public:
    
    int getYear(void);
    int getMonth(void);
    int getDay(void);
    Date (int aDay, int amonth, int ayear);
    
    void setYear(int);
    void setMonth(int);
    void setDay(int);
    string getDateString(void);
    
    
    Date();
    virtual ~Date();
};

#endif /* DATE_HPP_ */
