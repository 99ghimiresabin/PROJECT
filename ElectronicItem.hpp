

#ifndef ELECTRONICITEM_HPP_
#define ELECTRONICITEM_HPP_




class ElectronicItem: public OrderItem {
private:
	ItemType Type;
	int Warranty;
public:

	ItemType getType(void);
	int getWarranty(void);

	void setType(ItemType);
	void setWarranty(int);

	ElectronicItem();
	virtual ~ElectronicItem();
	virtual string whoAmI(void);
};

#endif /* ELECTRONICITEM_HPP_ */
