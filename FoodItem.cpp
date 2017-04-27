
#include "Date.hpp"
#include "OrderItem.hpp"
#include "FoodItem.hpp"

FoodItem::FoodItem() {
	// TODO Auto-generated constructor stub

}

FoodItem::~FoodItem() {
	// TODO Auto-generated destructor stub
}
Date FoodItem::getExpirationDate(void){
	return ExpirationDate;
}
int FoodItem::getCalories(void){
	return Calories;
}
int FoodItem::getFat(void){
	return Fat;
}

void FoodItem::setExpirationDate(int year,int month, int day){
	ExpirationDate.setYear(year);
	ExpirationDate.setMonth(month);
	ExpirationDate.setDay(day);
}
void FoodItem::setCalories(int anInt){
	Calories = anInt;
}
void FoodItem::setFat(int anInt){
	Fat = anInt;
}
string FoodItem::whoAmI(void){
	return "Food Item";
}
