
#include "OrderItem.hpp"
#include "Date.hpp"
#include "MediaItem.hpp"

MediaItem::MediaItem() {
	// TODO Auto-generated constructor stub

}

MediaItem::~MediaItem() {
	// TODO Auto-generated destructor stub
}

string MediaItem::getAuthorName(void){
	return AuthorName;
}
Date MediaItem::getPublicationDate(void){
	return PublicationDate;
}
string MediaItem::getISBNNumber(void){
	return ISBNNumber;
}

void MediaItem::setAuthorName(string aString){
	AuthorName = aString;
}
void MediaItem::setPublicationDate(int year, int month,int day){
	PublicationDate.setYear(year);
	PublicationDate.setMonth(month);
	PublicationDate.setDay(day);
}
void MediaItem::setISBNNumber(string aString){
	ISBNNumber = aString;
}
string MediaItem::whoAmI(void){
	return "Media Item";
}
