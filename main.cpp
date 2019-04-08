#include <iostream>
#include <string.h>
#include"String.h"
int main(){


String* test1= new String(20);
const char* s="Character sequence test";
String* test2 = new String(s);
std::cout << (test1->capacity()==20) << std::endl;
test1->reserve(10);
std::cout << (test1->capacity()==20) << std::endl;
test1->reserve(30);
std::cout << (test1->capacity()==30) << std::endl;
std::cout << not test1->empty()<< std::endl;

//Test Copy Constructor
std::cout << "Copy Constructor Test" << std::endl;
String* ctest = test1 ;
std::cout << (ctest->size()==4)<< std::endl;
std::cout << (ctest->capacity()==test1->capacity())<< std::endl;
//Test size()
std::cout << "Size Test" << std::endl;
String test_siz ;
String test_siz2("Hello,") ;
String test_siz3("Helloooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo") ;
std::cout << (test_siz.size()==0)<< std::endl;
std::cout << (test_siz2.size()==6)<< std::endl;
std::cout << (test_siz3.size()==100)<< std::endl;

//Test length()
std::cout<<(test1->length()==4)<<std::endl;

//Test c_str()
std::cout << "C_str Test" << std::endl;
char str1[] = {'T','o','t','o','\0'};
std::cout<<((strcmp(test1->c_str(),str1)==0))<<std::endl;

//Test operator=(char*)
*test1 = "bou";
*test1= "baracuda";
String test3="baudruche";


String test4=test3+*test1;
std::cout<<(test4.length()==17)<< (test4.capacity()==17) <<std::endl;

//Test max_size()
std::cout<<(test1->max_size()==100)<<std::endl;
std::cout<<(test2->max_size()==100)<<std::endl;

//Test clear()
std::cout << "Clear Test" << std::endl;
ctest->clear() ;
std::cout<<(ctest->size()==0)<<std::endl;
std::cout<<((strcmp(ctest->c_str(),"")==0))<<std::endl;
//Test limitation size
char c[]       ="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
test3=c;
std::cout<<(test3.size()==100)<<std::endl;
test3.reserve(10000);
std::cout<<(test3.size()==100)<<std::endl;
String* test5=new String(c);
std::cout<<(test5->size()==100)<<std::endl;
String test6 = test3+*test5;
std::cout<<(test6.size()==100)<<std::endl;

//Test operator=String
*test1= test3;
//Test operator=(char)
std::cout << "Operator= (char) Test" << std::endl;
test3 = 'C' ;
std::cout<<test3.c_str()<<std::endl;
//Test operator+(char*)
std::cout << "Operator+ (char*) Test" << std::endl;
String test7 ;
String test8 ;
test7 = "++" + test3 ;
test8 = test3 + "++" ;
std::cout<<test7.c_str()<<std::endl;
std::cout<<test8.c_str()<<std::endl;

//Test operator+(char)


String test9=test3+'+' ;
std::cout<<test9.c_str()<<std::endl;

//Test method resize()
test3.resize(11,'+');
std::cout<<test3.c_str()<<std::endl;
test3.resize(3,'+');
std::cout<<test3.c_str()<<std::endl;
//Test default Constructor
std::cout << "Default Constructor test" << std::endl;
String dctest ;
std::cout<<dctest.c_str()<<std::endl;
std::cout<<(dctest.size()==0)<<std::endl;


delete test1;
delete test2;
delete test5;
return 0;
}
