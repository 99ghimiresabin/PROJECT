
#include "Date.hpp"
#include "Customer.hpp"

Customer::Customer() {
	// TODO Auto-generated constructor stub

}

Customer::~Customer() {
	// TODO Auto-generated destructor stub
}

string Customer::getCustomerNumber(void){
	return CustomerNumber;
}
string Customer::getCustomerName(void){
	return CustomerName;
}
string Customer::getEmail(void){
	return Email;
}
Date Customer::getDateJoined(void){
	return DateJoined;
}


void Customer::setCustomerNumber(string aString){
	CustomerNumber = aString;
}
void Customer::setCustomerName(string aString){
	CustomerName = aString;
}
void Customer::setEmail(string aString){
	Email = aString;
}
void Customer::setDateJoined(int year,int month,int day){
 DateJoined.setYear(year);
 DateJoined.setMonth(month);
 DateJoined.setDay(day);
}
