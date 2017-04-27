
#include "Date.hpp"
#include "Customer.hpp"
#include "Order.hpp"
#include "OrderItem.hpp"
#include "FoodItem.hpp"
#include "MediaItem.hpp"
#include "ElectronicItem.hpp"
#include <iostream>
using namespace std;

Order::Order(Customer *Customer, string OrderNumber) {
	// TODO Auto-generated constructor stub
	OrderCustomer = Customer;

	readFoodItems(OrderNumber);
	readMediaItems(OrderNumber);
	readElectronicItems(OrderNumber);
}

Order::~Order() {
	// TODO Auto-generated destructor stub
}

string Order::getOrderNumber(void) {
	return OrderNumber;
}
Date Order::getOrderDate(void) {
	return OrderDate;
}
vector<OrderItem*> Order::getItemsInOrder(void) {
	return ItemsInOrder;
}
Customer* Order::getOrderCustomer(void) {
	return OrderCustomer;
}

void Order::setOrderNumber(string aString) {
	OrderNumber = aString;
}
void Order::setOrderDate(int year, int month, int day) {
	OrderDate.setYear(year);
	OrderDate.setMonth(month);
	OrderDate.setDay(day);
}
void Order::setItemsInOrder(vector<OrderItem*> aVector) {
	ItemsInOrder = aVector;
}
void Order::setOrderCustomer(Customer* aCustomer) {
	OrderCustomer = aCustomer;
}

void Order::readFoodItems(string orderNumber) {
	string tempOrderNumber;
	string tempItemNumber;
	string tempItemDescription;
	int tempQuantity;
	double tempCustomerCost;
	double tempVendorCost;
	bool tempTaxExempt;
	int tempYear;
	int tempMonth;
	int tempDay;
	int tempCalories;
	int tempFat;
	string line;

	string foodFile = "FoodItems.txt";
	ifstream isFoodFile;
	isFoodFile.open(foodFile.c_str());
	do {
		isFoodFile >> tempOrderNumber >> tempItemNumber >> tempItemDescription
				>> tempQuantity >> tempCustomerCost >> tempVendorCost
				>> tempTaxExempt >> tempYear >> tempMonth >> tempDay
				>> tempCalories >> tempFat;

		if (tempOrderNumber == orderNumber) {
			FoodItem *aFoodItem = new FoodItem;
			aFoodItem->setOrderNumber(tempOrderNumber);
			aFoodItem->setItemNumber(tempItemNumber);
			aFoodItem->setItemDescription(tempItemDescription);
			aFoodItem->setQuantity(tempQuantity);
			aFoodItem->setCustomerCost(tempCustomerCost);
			aFoodItem->setVendorCost(tempVendorCost);
			aFoodItem->setTaxExempt(tempTaxExempt);
			aFoodItem->setExpirationDate(tempYear, tempMonth, tempDay);
			aFoodItem->setCalories(tempCalories);
			aFoodItem->setFat(tempFat);
			ItemsInOrder.push_back(aFoodItem);
		}
	} while (getline(isFoodFile, line));

	isFoodFile.close();
}

void Order::readMediaItems(string orderNumber) {
	string tempOrderNumber;
	string tempItemNumber;
	string tempItemDescription;
	int tempQuantity;
	double tempCustomerCost;
	double tempVendorCost;
	bool tempTaxExempt;
	int tempYear;
	int tempMonth;
	int tempDay;
	string tempAuthor;
	string tempISBNNumber;
	string line;

	string mediaFile = "MediaItems.txt";
	ifstream isMediaFile;
	isMediaFile.open(mediaFile.c_str());
	do {

		isMediaFile >> tempOrderNumber >> tempItemNumber >> tempItemDescription
				>> tempQuantity >> tempCustomerCost >> tempVendorCost
				>> tempTaxExempt >> tempYear >> tempMonth >> tempDay
				>> tempAuthor >> tempISBNNumber;

		if (tempOrderNumber == orderNumber) {
			MediaItem *aMediaItem = new MediaItem;
			aMediaItem->setOrderNumber(tempOrderNumber);
			aMediaItem->setItemNumber(tempItemNumber);
			aMediaItem->setItemDescription(tempItemDescription);
			aMediaItem->setQuantity(tempQuantity);
			aMediaItem->setCustomerCost(tempCustomerCost);
			aMediaItem->setVendorCost(tempVendorCost);
			aMediaItem->setTaxExempt(tempTaxExempt);
			aMediaItem->setPublicationDate(tempYear, tempMonth, tempDay);
			aMediaItem->setAuthorName(tempAuthor);
			aMediaItem->setISBNNumber(tempISBNNumber);
			ItemsInOrder.push_back(aMediaItem);
		} //if
	} while (getline(isMediaFile, line));
	isMediaFile.close();
}
void Order::readElectronicItems(string orderNumber) {
	string tempOrderNumber;
	string tempItemNumber;
	string tempItemDescription;
	int tempQuantity;
	double tempCustomerCost;
	double tempVendorCost;
	string tempTaxExempt;
	string tempType;
	int tempWarrantyMonths;
	string line;

	string ElectronicFile = "ElectronicItems.txt";
	ifstream isElectronicFile;
	isElectronicFile.open(ElectronicFile.c_str());
	do {

		isElectronicFile >> tempOrderNumber >> tempItemNumber
				>> tempItemDescription >> tempQuantity >> tempCustomerCost
				>> tempVendorCost >> tempTaxExempt >> tempType
				>> tempWarrantyMonths;

		if (tempOrderNumber == orderNumber) {
			ElectronicItem *aElectronicItem = new ElectronicItem;
			aElectronicItem->setOrderNumber(tempOrderNumber);
			aElectronicItem->setItemNumber(tempItemNumber);
			aElectronicItem->setItemDescription(tempItemDescription);
			aElectronicItem->setQuantity(tempQuantity);
			aElectronicItem->setCustomerCost(tempCustomerCost);
			aElectronicItem->setVendorCost(tempVendorCost);
			if (tempTaxExempt == "Y") {
				aElectronicItem->setTaxExempt(true);
			} else {
				aElectronicItem->setTaxExempt(false);
			}
			if (tempType == "0") {
				aElectronicItem->setType(TV);
			} else if (tempType == "1") {
				aElectronicItem->setType(PS4);
			} else if (tempType == "2") {
				aElectronicItem->setType(DVDPLAYER);
			} else {
				aElectronicItem->setType(PHONE);
			}
			aElectronicItem->setWarrantyMonth(tempWarrantyMonths);
			ItemsInOrder.push_back(aElectronicItem);
		} //if
	} while (getline(isElectronicFile, line));

	isElectronicFile.close();

}

double Order::getTotalOfOrder(void) {
	vector<OrderItem*> ItemsInOrder;
	double cost;
	double totalCost = 0;
	int tempQuantity;
	double tempCustomerCost;

	for (unsigned int i = 0; i < ItemsInOrder.size(); i++) {
		tempQuantity = ItemsInOrder[i]->getQuantity();
		tempCustomerCost = ItemsInOrder[i]->getCustomerCost();
		cost = tempQuantity * tempCustomerCost;
		totalCost += cost;
	} //for
	return totalCost;
}
