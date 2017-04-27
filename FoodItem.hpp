

#ifndef FOODITEM_HPP_
#define FOODITEM_HPP_

class FoodItem : public OrderItem {
private:
	Date ExpirationDate;
	int Calories;
	int Fat;


public:
	Date getExpirationDate(void);
	int getCalories(void);
	int getFat(void);

	void setExpirationDate(int,int,int);
	void setCalories(int);
	void setFat(int);

	virtual string whoAmI(void);
	FoodItem();
	virtual ~FoodItem();
};

#endif /* FOODITEM_HPP_ */
