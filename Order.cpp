
#include "Date.hpp"
#include "Customer.hpp"
#include "Order.hpp"
#include "OrderItem.hpp"
#include "FoodItem.hpp"
#include "MediaItem.hpp"
#include "ElectronicItem.hpp"
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;

Order::Order(Customer *Customer, string OrderNumber)
{
    // TODO Auto-generated constructor stub
    OrderCustomer = Customer;
    
    readFoodItems(OrderNumber);
    readMediaItems(OrderNumber);
    readElectronicItems(OrderNumber);
}

Order::~Order()
{
    // TODO Auto-generated destructor stub
}

string Order::getOrderNumber(void)
{
    return OrderNumber;
}

string Order::getOrderDate(void)
{
        string result1;
        string result2;
        string result3;
        string Result;
        
    ostringstream convert1;
    ostringstream convert2;
    ostringstream convert3;
    
    
    
    convert1  << OrderDate.getYear();
    convert2 << OrderDate.getMonth();
    convert3 << OrderDate.getMonth();
    
    
        
        
        result1 = convert1.str();
        result2 = convert2.str();
        result3 = convert3.str();
        
        Result = result1 + "/" + result2 + "/" + result3 ;
        
        return Result;
        
        
        
        
        
    }

vector<OrderItem*> Order::getItemsInOrder(void)
{
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
    
   
    ifstream FoodFile;
    FoodFile.open("FoodItems.txt");
    
   while (getline(FoodFile, str))
    {
        FoodFile >> TempOrderNumber >> TempItemNumber >> TempItemDescription>> TempQuantity >> TempCustomerCost >> TempVendorCost>> TempTaxExempt >> TempYear >>TempMonth >> TempDay >> TempCalories >> TempFat;
        
        if (TempOrderNumber == orderNumber)
        {
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
    }
    
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
    

    ifstream MediaFile;
    MediaFile.open("MediaItems.txt");
    while (getline(MediaFile, str))
    {
        
        MediaFile >> TempOrderNumber >> TempItemNumber >> TempItemDescription>> TempQuantity >> TempCustomerCost >> TempVendorCost>> TempTaxExempt >> TempYear >> TempMonth >> TempDay>> TempAuthor >> TempISBNNumber;
        
        if (TempOrderNumber == orderNumber)
        {
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
        } //if
    }
    MediaFile.close();
}
void Order::readElectronicItems(string orderNumber)
{
    string TempOrderNumber;
    string TempItemNumber;
    string TempItemDescription;
    int    TempQuantity;
    double TempCustomerCost;
    double TempVendorCost;
    string TempTaxExempt;
    string TempType;
    int TempWarrantyMonths;
    string str;
    

    ifstream ElectronicFile;
    ElectronicFile.open("ElectronicItems.txt");
    while (getline(ElectronicFile, str))
    {
        
        ElectronicFile >> TempOrderNumber >> TempItemNumber
        >> TempItemDescription >> TempQuantity >> TempCustomerCost
        >> TempVendorCost >> TempTaxExempt >> TempType
        >> TempWarrantyMonths;
        
        if (TempOrderNumber == orderNumber)
        {
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
            aElectronicItem->setWarranty(TempWarrantyMonths);
            ItemsInOrder.push_back(aElectronicItem);
        } //if
    }
    
    ElectronicFile.close();
    
}

double Order::getTotalOfOrder(void)
{
    double Cost;
    double TotalCost = 0;
    int TempQuantity;
    double tempCustomerCost;
    
    for (unsigned int i = 0; i < ItemsInOrder.size(); i++)
    {
        TempQuantity = ItemsInOrder[i]->getQuantity();
        tempCustomerCost = ItemsInOrder[i]->getCustomerCost();
        Cost = TempQuantity * tempCustomerCost;
        TotalCost += Cost;
    } //for
    return TotalCost;
}

