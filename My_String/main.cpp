#include "MyString.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    MyString s1;
    MyString s2("Hello, World");
    s1 = s2 + ". What a nice day";
    s1.print();
    s1+=". A perfect day.";
    s1.print();
    MyString s3;
    s3 = "Nice to meet you!";
    MyString s4;
    s4 = s1 + s3;
    s1.print();
    s2.print();
    s3.print();
    s4.print();
    
    return 0;
}
