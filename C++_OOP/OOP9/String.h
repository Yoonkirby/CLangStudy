/*
 * 파일이름 : String.h
 * 작성자 : 윤성준
 * 업데이트 정보 : [2022, 06, 08] 파일버전 0.9
 */

#ifndef __STRING_H__
#define __STRING_H__
class String
{
private:
    int len;
    char * str;
public:
    String();
	String(const char * ref);
	String(const String& ref);
	~String();
	String& operator= (const String& ref);
	String& operator+= (const String& ref);
	bool operator== (const String& ref);
    String operator+ (const String& ref);

    friend ostream& operator<<(ostream& op, const String& ref);
    friend istream& operator>>(istream& ip, String& ref);
};
#endif