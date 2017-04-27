
#include "OrderItem.hpp"
#include <iostream>
#include <string>
using namespace std;

OrderItem::OrderItem() {
	// TODO Auto-generated constructor stub

}

OrderItem::~OrderItem() {
	// TODO Auto-generated destructor stub
}

string OrderItem::getOrderNumber(void){
	return OrderNumber;
}
string OrderItem::getItemNumber(void){
	return ItemNumber;
}
string OrderItem::getItemDescription(void){
	return ItemDescription;
}
int OrderItem::getQuantity(void){
	return Quantity;
}
double OrderItem::getCustomerCost(void){
	return CustomerCost;
}
double OrderItem::getVendorCost(void){
	return VendorCost;
}
bool OrderItem::getTaxExempt(void){
	return TaxExempt;
}

void OrderItem::setOrderNumber(string aString){
	OrderNumber = aString;
}
void OrderItem::setItemNumber(string aString){
	ItemNumber = aString;
}
void OrderItem::setItemDescription(string aString){
	ItemDescription = aString;
}
void OrderItem::setQuantity(int anInt){
	Quantity = anInt;
}
void OrderItem::setCustomerCost(double aDouble){
	CustomerCost = aDouble;
}
void OrderItem::setVendorCost(double aDouble){
	VendorCost = aDouble;
}
void OrderItem::setTaxExempt(bool aBool){
	TaxExempt = aBool;
}

string OrderItem::whoAmI(void){
	return "Order Item";
}
