//============================================================================
// Name        : PROJECT.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//*****************
//Project Name: PROJECT
//Project Description: Shopping cart
//Project Author: Ghimire, Sabin
//Is this an extra credit Project:  No
//Date completed: 4/23/2017
//Operating system used: Mac OS
//IDE Used:  XCode

//*****************

#include <iostream>
#include<vector>
#include "Date.hpp"
#include "Customer.hpp"
#include "Order.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>


using namespace std;

int main() {
	string customerFile = "CustomerFile.txt";
	ifstream CustomerFile;
	CustomerFile.open(customerFile.c_str());

	string orderFile = "OrderFile.txt";
	ifstream OrderFile;
	OrderFile.open(orderFile.c_str());

	vector<OrderItem*> theItems;
	vector<Customer*> theCustomers;
	vector<Order*> theOrders;

	string str;
	string tempCustomerNumber;
	string tempCustomerName;
	string tempEmail;
	int TempYear;
	int TempMonth;
	int TempDay;
	string tempOrderNumber;
	Customer* currentCustomer = nullptr;

	do {
		Customer *aCustomer = new Customer();
		CustomerFile >> tempCustomerNumber >> tempCustomerName >> tempEmail
				>> TempYear >> TempMonth >> TempDay;
		aCustomer->setCustomerNumber(tempCustomerNumber);
		aCustomer->setCustomerName(tempCustomerName);
		aCustomer->setEmail(tempEmail);
		aCustomer->setDateJoined(TempYear, TempMonth, TempDay);
		theCustomers.push_back(aCustomer);
	} while (getline(CustomerFile, str));
	CustomerFile.close();

    
    
	do {
		OrderFile >> tempOrderNumber >> TempYear >> TempMonth >> TempDay>> tempCustomerNumber;
		for (unsigned int i = 0; i < theCustomers.size(); i++)
        {
			if (theCustomers[i]->getCustomerNumber() == tempCustomerNumber)
            {
				currentCustomer = theCustomers[i];
			}
		}
		Order *aOrder = new Order(currentCustomer, tempOrderNumber);
		aOrder->setOrderNumber(tempOrderNumber);
		aOrder->setOrderDate(TempYear, TempMonth, TempDay);
		theOrders.push_back(aOrder);
	} while (getline(OrderFile,str));
	OrderFile.close();
    

	cout << left << setw(20) << "Order Report" << endl;

	for (unsigned int i = 0; i < theOrders.size(); i++) {

		cout << setw(20) << "==============================" << endl;
		cout << right << setw(15) << "Order ID" << setw(20) << "Customer ID"<< setw(20) << "Order Date" << setw(30) << "Customer" << endl;
		cout << right << setw(15) << "--------" << setw(20) << "-----------"<< setw(20) << "----------" << setw(30) << "--------" << endl;

		cout << right << setw(15) << theOrders[i]->getOrderNumber() << setw(20)
				<< theCustomers[i]->getCustomerNumber() << setw(20)
				<< theCustomers[i]->getCustomerNumber() << setw(30)
				<< theCustomers[i]->getCustomerName() << endl;
		cout << right << setw(21) << "--------------" << endl;

		currentCustomer = theOrders[i]->getOrderCustomer();
		theItems = theOrders[i]->getItemsInOrder();

		cout << right << setw(22) << "Food Items Ordered:" << setw(30) << "Item Number"<< setw(30) << "Item Description" << setw(20) << "Calories"<< setw(15) << "Cost" << endl;
		cout << right << setw(22) << "-------------------" << setw(30) << "-----------"<< setw(30) << "----------------" << setw(20) << "--------"<< setw(15) << "----" << endl;
       long  int fileSize = theOrders[i]->getItemsInOrder().size();

        for (unsigned int i = 0; i <  fileSize; i++) {
			cout << setw(50)<< theItems[i]->getItemNumber() << setw(30)<<theItems[i]->getItemDescription() << endl;
		}
        cout << right << setw(22) << "Media Items Ordered:" << setw(30) << "Item Number"
        << setw(30) << "Item Description" << setw(20) << "Calories"
        << setw(15) << "Cost" << endl;
        cout << right << setw(22) << "-------------------" << setw(30) << "-----------"
        << setw(30) << "----------------" << setw(20) << "--------"
        << setw(15) << "----" << endl;
    
        cout << "The total for your order is :"<< theOrders[i]->getTotalOfOrder()<< endl;
    }

for (unsigned int i = 0; i < theCustomers.size(); i++) {

}
//
//
//	delete aOrder;

	cout << "Program ending, have a nice day" << endl; // prints !!!Hello World!!!
	return 0;
} //main

