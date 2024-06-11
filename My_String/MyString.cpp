#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
    str = new char[81];
}

MyString::MyString(const char* s)
{
    str = new char[strlen(s)+1];
    strcpy_s(str, strlen(s)+1, s);
}

MyString::MyString(int n)
{
    str = new char[n+1];
}

MyString::~MyString()
{
    if (str)
        delete [] str;
}

MyString::MyString(const MyString& obj)
{
    this->str = new char[strlen(obj.str)+1];
    strcpy_s(this->str, strlen(obj.str)+1, obj.str);
}

void MyString::setString()
{
    cout << "enter string -> " << endl;
    char buff[255];
    gets_s(buff);
    if (str)
    {
        delete [] str;
        str = new char[strlen(buff)+1];
        strcpy_s(str, strlen(buff)+1, buff);
    }
    else
    {
        str = new char[strlen(buff)+1];
        strcpy_s(str, strlen(buff)+1, buff);
    }
}

char* MyString::getString() const
{
    return str;
}

void MyString::print() const
{
    cout << str << endl;
}

void MyString::MyStrcpy(const MyString& obj)
{
    if (this->str)
    {
        delete [] this->str;
        this->str = new char[strlen(obj.str)+1];
        strcpy_s(this->str, strlen(obj.str)+1, obj.str);
    }
    else
    {
        this->str = new char[strlen(obj.str)+1];
        strcpy_s(this->str, strlen(obj.str)+1, obj.str);
    }
}

bool MyString::MyStrStr(const char* s)
{
    if (str)
    {
        if (strlen(s)>0)
        {
            int c = 0, ind = 0;
            for (int i=0; i<strlen(str); i++)
                if (str[i] == s[0])
                    ind = i;
            for (int i=0, j=ind; i<strlen(s); i++, j++)
                if (str[j] == s[i])
                    c++;
            if (c == strlen(s))
                return true;
            else
                return false;
        }
    }
}

bool MyString::isSubStr(const MyString& obj)
{
    if (this->str && obj.str)
    {
        int c = 0, ind = 0;
        for (int i=0; i<strlen(this->str); i++)
            if (this->str[i] == obj.str[0])
                ind = i;
        for (int i=0, j=ind; i<strlen(obj.str); i++, j++)
            if (str[j] == obj.str[i])
                c++;
        if (c == strlen(obj.str))
            return true;
        else
            return false;
    }
}

int MyString::MyChr(char c)
{
    if (str)
    {
        int ind = 0, i = 0, count = 0;
        for (i; i<strlen(str); i++)
        {
            if (str[i] == c)
            {
                ind = i;
                return ind;
            }
            else
                count++;
        }
        if (count == strlen(str))
            return -1;
    }
}

int MyString::MyChr_n(char c)
{
    if (str)
    {
        int ind = 0, i = strlen(str)-1, count = 0;
        for (i; i>=0; i--)
        {
            if (str[i] == c)
            {
                ind = i;
                return ind;
            }
            else
                count++;
        }
        if (count == strlen(str))
            return -1;
    }
}

int MyString::MyStrLen()
{
    if (str)
    {
        int c = 0, i = 0;
        while (str[i]!='\0')
        {
            c++;
            i++;
        }
        return c;
    }
}

void MyString::MyStrCat(const MyString& obj)
{
    if (this->str && obj.str)
    {
        int s = strlen(this->str) + strlen(obj.str) + 1;
        char* t = new char[s];
        int i = 0, j = 0;
        for (i; i<strlen(this->str); i++)
            t[i] = this->str[i];
        for (i, j; j<strlen(obj.str); i++, j++)
            t[i] = obj.str[j];
        t[i] = '\0';
        delete [] this->str;
        this->str = t;
    }
}

void MyString::MyStrCat(const char* s)
{
    if (str && strlen(s)>0)
    {
        int l = strlen(str) + strlen(s) + 1;
        char* t = new char[l];
        int i = 0, j = 0;
        for (i; i<strlen(str); i++)
            t[i] = str[i];
        for (i, j; j<strlen(s); i++, j++)
            t[i] = s[j];
        t[i] = '\0';
        delete [] str;
        str = t;
    }
}

void MyString::MyDelChr(char c)
{
    int count = 0;
    for (int i=0; i<strlen(str); i++)
        if (str[i] == c)
            count++;
    if (count>0)
    {
        char* t = new char[strlen(str)-count];
        int i=0, j=0;
        while (i<strlen(str))
        {
            if (str[i]!=c)
            {
                t[j] = str[i];
                j++;
            }
            i++;
        }
        delete [] str;
        str = t;
    }
}

int MyString::MyStrCmp(const MyString& obj)
{
    int s1 = 0, s2 = 0;
    for (int i=0; i<strlen(this->str); i++)
        s1+=(int)this->str[i];
    for (int i=0; i<strlen(obj.str); i++)
        s2+=(int)obj.str[i];
    if (s1<s2)
        return -1;
    else if (s1>s2)
        return 1;
    else
        return 0;
}

bool MyString::operator>(const MyString& obj)
{
    if (MyStrCmp(obj)==1)
        return true;
    else
        return false;
}

bool MyString::operator<(const MyString& obj)
{
    if (MyStrCmp(obj) == -1)
        return true;
    else
        return false;
}

bool MyString::operator>=(const MyString& obj)
{
    if ((MyStrCmp(obj) == 0) || (MyStrCmp(obj) == 1))
        return true;
    else
        return false;
}

bool MyString::operator<=(const MyString& obj)
{
    if ((MyStrCmp(obj) == -1) || (MyStrCmp(obj) == 0))
        return true;
    else
        return false;
}

bool MyString::operator==(const MyString& obj)
{
    if (MyStrCmp(obj) == 0)
        return true;
    else
        return false;
}

bool MyString::operator!=(const MyString& obj)
{
    if (MyStrCmp(obj) != 0)
        return true;
    else
        return false;
}

MyString& MyString::operator+=(const MyString& obj)
{
    MyStrCat(obj);
    return *this;
}

MyString MyString::operator+(const MyString& obj)
{
    int s = strlen(this->str) + strlen(obj.str)+1;
    char* t = new char[s];
    strcpy_s(t, strlen(this->str)+1, this->str);
    strcat_s(t, s, obj.str);

    return t;
}

MyString& MyString::operator+=(const char* s)
{
    MyStrCat(s);
    return *this;
}

MyString MyString::operator+(const char* s)
{
    int l = strlen(str) + strlen(s)+1;
    char* t = new char[l];
    strcpy_s(t, strlen(str)+1, str);
    strcat_s(t, l, s);

    return t;
}

MyString& MyString::operator=(const MyString& obj)
{
    if (this->str == obj.str)
        return *this;
    if (this->str)
        delete [] this->str;
    this->str = new char[strlen(obj.str)+1];
    strcpy_s(this->str, strlen(obj.str)+1, obj.str);

    return *this;
}

MyString& MyString::operator=(const char* s)
{
    if (str)
        delete [] str;
    str = new char[strlen(s)+1];
    strcpy_s(str, strlen(s)+1, s);

    return *this;
}
