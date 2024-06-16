#pragma once

class MyString
{
private:
    char* str;
public:
    MyString();
    MyString(const char* s);
    MyString(int n);
    ~MyString();
    MyString(const MyString &obj);
    MyString(MyString &&obj);
    void setString();
    char* getString() const;
    void print() const;
    void MyStrcpy(const MyString &obj);
    bool MyStrStr(const char* s);
    bool isSubStr(const MyString &obj);
    int MyChr(char c);
    int MyChr_n(char c);
    int MyStrLen();
    void MyStrCat(const MyString &obj);
    void MyStrCat(const char* s);
    void MyDelChr(char c);
    int MyStrCmp(const MyString &obj);
    bool operator> (const MyString &obj);
    bool operator< (const MyString &obj);
    bool operator>= (const MyString &obj);
    bool operator<= (const MyString &obj);
    bool operator== (const MyString &obj);
    bool operator!= (const MyString &obj);
    MyString& operator+= (const MyString &obj);
    MyString operator+ (const MyString &obj);
    MyString& operator+= (const char* s);
    MyString operator+ (const char* s);
    MyString& operator= (const MyString &obj);
    MyString& operator= (const char* s);
    MyString& operator= (MyString &&obj);
};

