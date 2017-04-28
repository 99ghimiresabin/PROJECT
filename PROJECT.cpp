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
#include <vector>
#include "Date.hpp"
#include "Customer.hpp"
#include "Order.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include "ElectronicItem.hpp"
#include "MediaItem.hpp"

using namespace std;

int main(int Argc, char *Argv[] )
{
    
    if(Argc > 2)
    {
        cout << "Error Exist ! more than two arguements " << endl;
        return NULL;
    }

    
	ifstream CustomerFile;
	CustomerFile.open("CustomerFile.txt");

	ifstream OrderFile;
	OrderFile.open("OrderFile.txt");

	vector<OrderItem*> TheOrderItem;
	vector<Customer*> TheCustomer;
	vector<Order*> TheOrder;

	string str;
	string TempCustomerNumber;
	string TempCustomerName;
	string TempEmail;
	int TempYear;
	int TempMonth;
	int TempDay;
	string TempOrderNumber;
	Customer* myCustomer = nullptr;

	do
    {
		Customer *aCustomer = new Customer();
		CustomerFile >> TempCustomerNumber >> TempCustomerName >> TempEmail>> TempYear >> TempMonth >> TempDay;
		aCustomer->setCustomerNumber(TempCustomerNumber);
		aCustomer->setCustomerName(TempCustomerName);
		aCustomer->setEmail(TempEmail);
		aCustomer->setDateJoined(TempYear, TempMonth, TempDay);
		TheCustomer.push_back(aCustomer);
    }
    while (getline(CustomerFile, str));
	CustomerFile.close();

    
    
	do
    {
		OrderFile >> TempOrderNumber >> TempYear >> TempMonth >> TempDay>> TempCustomerNumber;
		for ( int i = 0; i < TheCustomer.size(); i++)
        {
			if (TheCustomer[i]->getCustomerNumber() == TempCustomerNumber)
            {
				myCustomer = TheCustomer[i];
			}
		}
        
		Order *anOrder = new Order(myCustomer, TempOrderNumber);
		anOrder->setOrderNumber(TempOrderNumber);
		anOrder->setOrderDate(TempYear, TempMonth, TempDay);
		TheOrder.push_back(anOrder);
    }
    while (getline(OrderFile,str));
	OrderFile.close();
    
    
	cout << "Order Report" << endl;
    
    

    long int orderSize = TheOrder.size();
	for (int i = 0; i < orderSize ; i++) {

		cout << setw(21) <<"=====================" << endl;
		cout << setw(16) << "Order ID" << setw(21) << "Customer ID"<< setw(21) << "Order Date" << setw(31) << "Customer" << endl;
		cout << setw(16) << "--------" << setw(21) << "-----------"<< setw(21) << "----------" << setw(31) << "--------" << endl;

		cout << setw(16) << TheOrder[i]->getOrderNumber() << setw(21)<< TheCustomer[i]->getCustomerNumber()<< setw(21)<< TheOrder[i]->getOrderDate() << setw(33)<< TheCustomer[i]->getCustomerName() << endl;
		cout << setw(21) << "--------------" << endl;

		myCustomer = TheOrder[i]->getOrderCustomer();
		TheOrderItem = TheOrder[i]->getItemsInOrder();
         long  int ItemsInOrderFileSize = TheOrder[i]->getItemsInOrder().size();

        cout << setw(22) << "Food Items Ordered:" << setw(29)<< "Item Number" << setw(30) << "Item Description"<< setw(20) << "Calories" << setw(15) << "Cost" << endl;
       cout  << setw(52)<< "-----------" << setw(30) << "----------------"<< setw(20) << "--------" << setw(15) << "----" << endl;
        
        
        
        for (int x = 0; x < ItemsInOrderFileSize;x++)
        {
            if (TheOrderItem[x]->whoAmI() == "Food Item")
            {
                FoodItem* foodItem = static_cast<FoodItem *>(TheOrderItem[x]);
                cout<< setw(52) << TheOrderItem[x]->getItemNumber()<< setw(30) << TheOrderItem[x]->getItemDescription()<< setw(20) << foodItem->getCalories() << setw(10)<< "$" << TheOrderItem[x]->getCustomerCost() << endl;
                
            }
        }
        
        cout << setw(21) << "--------------" << endl;
        cout << setw(22) << "Media Items Ordered:" << setw(30)<< "Item Number" << setw(30) << "Item Description"<< setw(20) << "ISBN" << setw(15) << "Cost" <<endl;
        cout << setw(52)<< "-----------" << setw(30) << "----------------"<< setw(20) << "--------" << setw(15) << "----" << endl;
        
        
        
        
        for (int i= 0; i < ItemsInOrderFileSize; i++)
        {
            if (TheOrderItem[i]->whoAmI() == "Media Item")
            {
                MediaItem* mediaItem = static_cast<MediaItem *>(TheOrderItem[i]);
                cout << setw(52) << TheOrderItem[i]->getItemNumber()<< setw(30) << TheOrderItem[i]->getItemDescription()<< setw(20) << mediaItem->getISBNNumber()<< setw(10) << "$" <<TheOrderItem[i]->getCustomerCost()<< endl;
            }
        }
        
        cout << setw(21) << "--------------" << endl;
        cout << setw(22) << "Electronic Items Ordered:" << setw(30)<< "Item Number" << setw(30) << "Item Description"<< setw(20) << "Warrenty" << setw(12) << "Cost" <<endl;
        cout << setw(52)<< "-----------" << setw(30) << "----------------"<< setw(20) << "--------" << setw(15) << "----" << endl;
        
        

        for (int i = 0; i <ItemsInOrderFileSize; i++)
        {
            if (TheOrderItem[i]->whoAmI() == "Electronic Item")
            {
                ElectronicItem* electronicItem =static_cast<ElectronicItem *>(TheOrderItem[i]);
                cout << setw(52)<< TheOrderItem[i]->getItemNumber()<< setw(30) << TheOrderItem[i]->getItemDescription()<< setw(20) <<electronicItem->getWarranty()
                << setw(10) << "$" << TheOrderItem[i]->getCustomerCost()<< endl;
            }
        }
        cout << "Total for this order will be: " << "$"<< TheOrder[i]->getTotalOfOrder() << endl;
    }
    
    for(int i = 0; i < TheCustomer.size(); i++)
    {
        delete TheCustomer[i];
    }
    
    
    for (int i = 0; i < TheOrderItem.size(); i++)
        {
            delete TheOrderItem[i];
        }

	return 0;
}

