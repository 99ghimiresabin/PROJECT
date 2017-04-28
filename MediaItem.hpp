
#ifndef MEDIAITEM_HPP_
#define MEDIAITEM_HPP_
#include <string>
using namespace std;


class MediaItem: public OrderItem {
private:
    string AuthorName;
    Date PublicationDate;
    string ISBNNumber;
public:
    
    string getAuthorName(void);
    Date getPublicationDate(void);
    string getISBNNumber(void);
    
    void setAuthorName(string);
    void setPublicationDate(int,int,int);
    void setISBNNumber(string);
    
    MediaItem();
    virtual ~MediaItem();
    
    virtual string whoAmI(void);
};

#endif /* MEDIAITEM_HPP_ */
