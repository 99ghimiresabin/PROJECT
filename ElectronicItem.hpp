

#ifndef ELECTRONICITEM_HPP_
#define ELECTRONICITEM_HPP_




class ElectronicItem: public OrderItem {
private:
	TypeOfItem Type;
	int WarrantyMonths;
public:

	TypeOfItem getType(void);
	int getWarrantyMonth(void);

	void setType(TypeOfItem);
	void setWarrantyMonth(int);

	ElectronicItem();
	virtual ~ElectronicItem();
	virtual string whoAmI(void);
};

#endif /* ELECTRONICITEM_HPP_ */
