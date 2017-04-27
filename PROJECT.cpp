//============================================================================
// Name        : CS2_Chapter14_15_Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//*****************
//Project Name: PROJECT !%
//Project Description: Shopping cart
//Project Author: Ghimire, Sabin
//Is this an extra credit Project:  No
//Date completed: 4/23/2017
//Operating system used: Mac OS
//IDE Used:  XCode

//*****************

#include <iostream>
using namespace std;
#include<vector>
#include "Date.hpp"
#include "Customer.hpp"
//#include "OrderItem.hpp"
#include "Order.hpp"
//#include "FoodItem.hpp"
//#include "MediaItem.hpp"
//#include "ElectronicItem.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
	string customerFile = "CustomerFile.txt";
	ifstream isCustomerFile;
	isCustomerFile.open(customerFile.c_str());

	string orderFile = "OrderFile.txt";
	ifstream isOrderFile;
	isOrderFile.open(orderFile.c_str());

	vector<OrderItem*> theItems;
	vector<Customer*> theCustomers;
	vector<Order*> theOrders;

	string line;
	string tempCustomerNumber;
	string tempCustomerName;
	string tempEmail;
	int tempYear;
	int tempMonth;
	int tempDay;
	string tempOrderNumber;
	Customer* currentCustomer = nullptr;

	do {
		Customer *aCustomer = new Customer();
		isCustomerFile >> tempCustomerNumber >> tempCustomerName >> tempEmail
				>> tempYear >> tempMonth >> tempDay;
		aCustomer->setCustomerNumber(tempCustomerNumber);
		aCustomer->setCustomerName(tempCustomerName);
		aCustomer->setEmail(tempEmail);
		aCustomer->setDateJoined(tempYear, tempMonth, tempDay);
		theCustomers.push_back(aCustomer);
	} while (getline(isCustomerFile, line));
	isCustomerFile.close();

	do {
		isOrderFile >> tempOrderNumber >> tempYear >> tempMonth >> tempDay
				>> tempCustomerNumber;
		for (unsigned int i = 0; i < theCustomers.size(); i++) {
			if (theCustomers[i]->getCustomerNumber() == tempCustomerNumber) {
				currentCustomer = theCustomers[i];
			} //if
		} //for
		Order *aOrder = new Order(currentCustomer, tempOrderNumber);

		aOrder->setOrderNumber(tempOrderNumber);
		aOrder->setOrderDate(tempYear, tempMonth, tempDay);

		theOrders.push_back(aOrder);
	} while (getline(isOrderFile, line));
	isOrderFile.close();

	cout << left << setw(20) << "Order Report" << endl;

	for (unsigned int i = 0; i < theOrders.size(); i++) {

		cout << setw(20) << "==============================" << endl;
		cout << right << setw(15) << "Order ID" << setw(20) << "Customer ID"
				<< setw(20) << "Order Date" << setw(30) << "Customer" << endl;
		cout << right << setw(15) << "--------" << setw(20) << "-----------"
				<< setw(20) << "----------" << setw(30) << "--------" << endl;

		cout << right << setw(15) << theOrders[i]->getOrderNumber() << setw(20)
				<< theCustomers[i]->getCustomerNumber() << setw(20)
				<< theCustomers[i]->getCustomerNumber() << setw(30)
				<< theCustomers[i]->getCustomerName() << endl;
		cout << right << setw(21) << "--------------" << endl;

		currentCustomer = theOrders[i]->getOrderCustomer();
		theItems = theOrders[i]->getItemsInOrder();

		cout << right << setw(22) << "Food Items Ordered:" << setw(30) << "Item Number"
				<< setw(30) << "Item Description" << setw(20) << "Calories"
				<< setw(15) << "Cost" << endl;
		cout << right << setw(22) << "-------------------" << setw(30) << "-----------"
						<< setw(30) << "----------------" << setw(20) << "--------"
						<< setw(15) << "----" << endl;

		for (unsigned int x = 0; x <  theOrders[i]->getItemsInOrder().size(); x++) {
			cout << theItems[x]->getItemNumber() << theItems[x]->getItemDescription() << endl;
		//	cout << theItems[x]->getItemDescription() << endl;
		} //nested for
	} //for
//	for (unsigned int i = 0; i < theCustomers.size(); i++) {
//		delete aCustomer[i];
//	} //for
//
//
//	delete aOrder;

	cout << "Program ending, have a nice day" << endl; // prints !!!Hello World!!!
	return 0;
} //main

