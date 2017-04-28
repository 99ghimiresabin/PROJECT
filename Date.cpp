

#include "Date.hpp"
#include<iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

Date::Date()
{
    // TODO Auto-generated constructor stub
    
}

Date::~Date()
{
    // TODO Auto-generated destructor stub
}

int Date::getYear(void)
{
    return Year;
}

int Date::getMonth(void)
{
    return Month;
}

int Date::getDay(void)
{
    return Day;
}


void Date::setYear(int anInt)
{
    Year = anInt;
}

void Date::setMonth(int anInt)
{
    Month = anInt;
}

void Date::setDay(int anInt)
{
    Day = anInt;
}


