
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
Date Order::getOrderDate(void)
{
	return OrderDate;
}
vector<OrderItem*> Order::getItemsInOrder(void)
{
	return ItemsInOrder;
}
Customer* Order::getOrderCustomer(void)
{
	return OrderCustomer;
}

void Order::setOrderNumber(string aString)
{
	OrderNumber = aString;
}
void Order::setOrderDate(int year, int month, int day)
{
	OrderDate.setYear(year);
	OrderDate.setMonth(month);
	OrderDate.setDay(day);
}
void Order::setItemsInOrder(vector<OrderItem*> aVector)
{
	ItemsInOrder = aVector;
}
void Order::setOrderCustomer(Customer* aCustomer)
{
	OrderCustomer = aCustomer;
}

void Order::readFoodItems(string orderNumber)
{
	string TempOrderNumber;
	string TempItemNumber;
	string TempItemDescription;
	int TempQuantity;
	double TempCustomerCost;
	double TempVendorCost;
	bool TempTaxExempt;
	int TempYear;
	int TempMonth;
	int TempDay;
	int TempCalories;
	int TempFat;
	string str;

	string foodFile = "FoodItems.txt";
	ifstream FoodFile;
	FoodFile.open(foodFile.c_str());
	do
    {
		FoodFile >> TempOrderNumber >> TempItemNumber >> TempItemDescription
				>> TempQuantity >> TempCustomerCost >> TempVendorCost
				>> TempTaxExempt >> TempYear >> TempMonth >> TempDay
				>> TempCalories >> TempFat;

		if (TempOrderNumber == orderNumber) {
			FoodItem *aFoodItem = new FoodItem;
			aFoodItem->setOrderNumber(TempOrderNumber);
			aFoodItem->setItemNumber(TempItemNumber);
			aFoodItem->setItemDescription(TempItemDescription);
			aFoodItem->setQuantity(TempQuantity);
			aFoodItem->setCustomerCost(TempCustomerCost);
			aFoodItem->setVendorCost(TempVendorCost);
			aFoodItem->setTaxExempt(TempTaxExempt);
			aFoodItem->setExpirationDate(TempYear, TempMonth, TempDay);
			aFoodItem->setCalories(TempCalories);
			aFoodItem->setFat(TempFat);
			ItemsInOrder.push_back(aFoodItem);
		}
	} while (getline(FoodFile, str));

	FoodFile.close();
}

void Order::readMediaItems(string orderNumber)
{
	string TempOrderNumber;
	string TempItemNumber;
	string TempItemDescription;
	int TempQuantity;
	double TempCustomerCost;
	double TempVendorCost;
	bool TempTaxExempt;
	int TempYear;
	int TempMonth;
	int TempDay;
	string TempAuthor;
	string TempISBNNumber;
	string str;

	string mediaFile = "MediaItems.txt";
	ifstream
    MediaFile;
	MediaFile.open(mediaFile.c_str());
	do {

		MediaFile >> TempOrderNumber >> TempItemNumber >> TempItemDescription>> TempQuantity >> TempCustomerCost >> TempVendorCost>> TempTaxExempt >> TempYear >> TempMonth >> TempDay>> TempAuthor >> TempISBNNumber;

		if (TempOrderNumber == orderNumber) {
			MediaItem *aMediaItem = new MediaItem;
			aMediaItem->setOrderNumber(TempOrderNumber);
			aMediaItem->setItemNumber(TempItemNumber);
			aMediaItem->setItemDescription(TempItemDescription);
			aMediaItem->setQuantity(TempQuantity);
			aMediaItem->setCustomerCost(TempCustomerCost);
			aMediaItem->setVendorCost(TempVendorCost);
			aMediaItem->setTaxExempt(TempTaxExempt);
			aMediaItem->setPublicationDate(TempYear, TempMonth, TempDay);
			aMediaItem->setAuthorName(TempAuthor);
			aMediaItem->setISBNNumber(TempISBNNumber);
			ItemsInOrder.push_back(aMediaItem);
		}
	} while (getline(MediaFile, str));
	MediaFile.close();
}
void Order::readElectronicItems(string orderNumber)
{
	string TempOrderNumber;
	string TempItemNumber;
	string TempItemDescription;
	int TempQuantity;
	double TempCustomerCost;
	double TempVendorCost;
	string TempTaxExempt;
	string TempType;
	int TempWarrantyMonths;
	string line;

	string ElectronicFile = "ElectronicItems.txt";
	ifstream isElectronicFile;
	isElectronicFile.open(ElectronicFile.c_str());
	do {

		isElectronicFile >> TempOrderNumber >> TempItemNumber
				>> TempItemDescription >> TempQuantity >> TempCustomerCost
				>> TempVendorCost >> TempTaxExempt >> TempType
				>> TempWarrantyMonths;

		if (TempOrderNumber == orderNumber) {
			ElectronicItem *aElectronicItem = new ElectronicItem;
			aElectronicItem->setOrderNumber(TempOrderNumber);
			aElectronicItem->setItemNumber(TempItemNumber);
			aElectronicItem->setItemDescription(TempItemDescription);
			aElectronicItem->setQuantity(TempQuantity);
			aElectronicItem->setCustomerCost(TempCustomerCost);
			aElectronicItem->setVendorCost(TempVendorCost);
			if (TempTaxExempt == "Y")
            {
				aElectronicItem->setTaxExempt(true);
			} else
            {
				aElectronicItem->setTaxExempt(false);
			}
			if (TempType == "0")
            {
				aElectronicItem->setType(TV);
			} else if (TempType == "1")
            {
				aElectronicItem->setType(PS4);
			} else if (TempType == "2")
            {
				aElectronicItem->setType(DVDPLAYER);
			} else
            {
				aElectronicItem->setType(PHONE);
			}
			aElectronicItem->setWarrantyMonth(TempWarrantyMonths);
			ItemsInOrder.push_back(aElectronicItem);
		}
	}
    while (getline(isElectronicFile, line));

	isElectronicFile.close();

}

double Order::getTotalOfOrder(void)
{
	vector<OrderItem*> ItemsInOrder;
	double cost;
	double totalCost = 0;
	int tempQuantity;
	double tempCustomerCost;

	for (unsigned int i = 0; i < ItemsInOrder.size(); i++)
    {
		tempQuantity = ItemsInOrder[i]->getQuantity();
		tempCustomerCost = ItemsInOrder[i]->getCustomerCost();
		cost = tempQuantity * tempCustomerCost;
		totalCost += cost;
	}
	return totalCost;
}
