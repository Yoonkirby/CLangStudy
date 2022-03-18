#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char * title;   //책의 제목
    char * isbn;    //국제표준도서번호
    int price;      //책의 정가
public:
    Book(const char * btitle, const char * bisbn, int bprice)
        :price(bprice)
    {
        title = new char[strlen(btitle)+1];
        isbn = new char[strlen(bisbn)+1];
        strcpy(title, btitle);
        strcpy(isbn, bisbn);
    }
    Book(const Book& copy) : price(copy.price)
    {
        title = new char[strlen(copy.title)+1];
        isbn = new char[strlen(copy.isbn)+1];
        strcpy(title, copy.title);
        strcpy(isbn, copy.isbn);
    }
    Book& operator=(const Book& copy)
    {
        title = new char[strlen(copy.title)+1];
        isbn = new char[strlen(copy.isbn)+1];
        strcpy(title, copy.title);
        strcpy(isbn, copy.isbn);
        price = copy.price;
    }
    void ShowBookInfo() const
    {
        cout<<"title : "<<title<<endl;
        cout<<"ISBN : "<<isbn<<endl;
        cout<<"price : "<<price<<endl;
    }
    ~Book()
    {
        delete []title;
        delete []isbn;
    }
};

class EBook : public Book
{
private:
    char * DRMKey;  //보안관련 키
public:
    EBook(const char * ebtitle, const char * ebisbn, int ebprice, const char * ebDRMKey)
        : Book(ebtitle, ebisbn, ebprice)
    {
        DRMKey = new char[strlen(ebDRMKey)+1];
        strcpy(DRMKey, ebDRMKey);
    }
    EBook(const EBook& copy) : Book(copy)
    {
        DRMKey = new char[strlen(copy.DRMKey)+1];
        strcpy(DRMKey,copy.DRMKey);
    }
    EBook& operator=(const EBook& copy)
    {
        Book::operator=(copy);
        DRMKey = new char[strlen(copy.DRMKey)+1];
        strcpy(DRMKey,copy.DRMKey);
    }
    void ShowEBookInfo() const
    {
        ShowBookInfo();
        cout<<"DRMKey : "<<DRMKey<<endl;
    }
    ~EBook()
    {
        delete []DRMKey;
    }
};

int main(void)
{
    Book book("Good C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout<<endl;
    EBook ebook("Good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    cout<<endl<<endl;

    EBook nebook = ebook;
    nebook.ShowEBookInfo();
    cout<<endl;
    EBook cebook("Bad C++ ebook", "666-13579-111-3", 5000, "9fqwf58v7a");
    nebook = cebook;
    nebook.ShowEBookInfo();
    return 0;
}