
#ifndef DATE_HPP_
#define DATE_HPP_

class Date {
	private:
	int Year;
	int Month;
	int Day;

public:

	int getYear(void);
	int getMonth(void);
	int getDay(void);


	void setYear(int);
	void setMonth(int);
	void setDay(int);

	Date();
	virtual ~Date();
};

#endif /* DATE_HPP_ */
