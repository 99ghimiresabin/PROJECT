
#include "OrderItem.hpp"
#include "ElectronicItem.hpp"

ElectronicItem::ElectronicItem() {
	// TODO Auto-generated constructor stub

}

ElectronicItem::~ElectronicItem() {
	// TODO Auto-generated destructor stub
}

TypeOfItem ElectronicItem::getType(void){
	return Type;
}
int ElectronicItem::getWarrantyMonth(void){
	return WarrantyMonths;
}

void ElectronicItem::setType(TypeOfItem tempType){
	Type = tempType;
}
void ElectronicItem::setWarrantyMonth(int anInt){
	WarrantyMonths = anInt;
}

string ElectronicItem::whoAmI(void){
	return "Electronic Item";
}
