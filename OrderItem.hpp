

#ifndef ORDERITEM_HPP_
#define ORDERITEM_HPP_
#include <string>
using namespace std;

enum ItemType
{
    TV, PS4, DVDPLAYER, PHONE
};

class OrderItem {
private:
    string OrderNumber;
    string ItemNumber;
    string ItemDescription;
    int Quantity;
    double CustomerCost;
    double VendorCost;
    bool TaxExempt;
public:
    OrderItem();
    virtual ~OrderItem();
    
    string getOrderNumber(void);
    string getItemNumber(void);
    string getItemDescription(void);
    int getQuantity(void);
    double getCustomerCost(void);
    double getVendorCost(void);
    bool getTaxExempt(void);
    
    void setOrderNumber(string);
    void setItemNumber(string);
    void setItemDescription(string);
    void setQuantity(int);
    void setCustomerCost(double);
    void setVendorCost(double);
    void setTaxExempt(bool);
    
    virtual string whoAmI(void)=0; // Pure Virtual Function
    
};

#endif /* ORDERITEM_HPP_ */
