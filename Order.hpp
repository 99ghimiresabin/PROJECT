
#ifndef ORDER_HPP_
#define ORDER_HPP_
#include "OrderItem.hpp"
#include "FoodItem.hpp"
#include <vector>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip>

class Order{
private:
	string OrderNumber;
	Date OrderDate;
	vector<OrderItem*> ItemsInOrder;
	Customer *OrderCustomer;


public:

	string getOrderNumber(void);
	Date getOrderDate(void);
	vector<OrderItem*> getItemsInOrder(void);
	Customer* getOrderCustomer(void);

	void setOrderNumber(string);
	void setOrderDate(int,int,int);
	void setItemsInOrder(vector<OrderItem*>);
	void setOrderCustomer(Customer*);

	void readFoodItems(string);
	void readMediaItems(string);
	void readElectronicItems(string);

	double getTotalOfOrder(void);

	Order(Customer*,string);
	virtual ~Order();
};

#endif /* ORDER_HPP_ */
