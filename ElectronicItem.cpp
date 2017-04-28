
#include "OrderItem.hpp"
#include "ElectronicItem.hpp"

ElectronicItem::ElectronicItem() {
    // TODO Auto-generated constructor stub
    
}

ElectronicItem::~ElectronicItem() {
    // TODO Auto-generated destructor stub
}

ItemType ElectronicItem::getType(void){
    return Type;
}
int ElectronicItem::getWarranty(void)
{
    return Warranty;
}

void ElectronicItem::setType(ItemType tempType){
    Type = tempType;
}
void ElectronicItem::setWarranty(int anInt){
    Warranty = anInt;
}

string ElectronicItem::whoAmI(void){
    return "Electronic Item";
}
