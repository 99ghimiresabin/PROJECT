

#include "Date.hpp"
#include<iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

Date::Date() {
	// TODO Auto-generated constructor stub

}

Date::~Date() {
	// TODO Auto-generated destructor stub
}

int Date::getYear(void){
	return Year;
}

int Date::getMonth(void){
	return Month;
}

int Date::getDay(void){
	return Day;
}


void Date::setYear(int anInt){
	Year = anInt;
}

void Date::setMonth(int anInt){
	Month = anInt;
}

void Date::setDay(int anInt){
	Day = anInt;
}
string Date::getDateString(int aDay,int aMonth, int aYear)
{
    string result1;
    string result2;
    string result3;
    string Result;
    
    ostringstream convert1;
    ostringstream convert2;
    ostringstream convert3;
    
    convert1 << aDay;
    convert2 << aMonth;
    convert3 << aYear;
    
    result1 = convert1.str();
    result2 = convert2.str();
    result3 = convert3.str();
    
    Result = result1 + "/" + result2 + "/" + result3 ;
    
    return Result;
    
    
    
    
    
}

