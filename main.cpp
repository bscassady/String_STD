#include <iostream>
#include <string.h>
#include"String.h"
int main(){


String* test1= new String(20);
const char* s="Character sequence test";
String* test2 = new String(s);

std::cout<<"Test capacity()"<<std::endl;//Test capacity()
std::cout << (test1->capacity()==20) << std::endl;
std::cout<<"Test reserve()"<<std::endl;//Test Reserve
test1->reserve(10);
std::cout << (test1->capacity()==20) << std::endl;
test1->reserve(0);
std::cout << (test1->capacity()==20) << std::endl;
test1->reserve(30);
std::cout << (test1->capacity()==30) << std::endl;

std::cout<<"Test empty()"<<std::endl;//Test empty()
std::cout << not test1->empty()<< std::endl;
String testvide("");
std::cout <<  testvide.empty()<< std::endl;
//Test Copy Constructor
String* ctest = test1 ;
std::cout << (ctest->size()==4)<< std::endl;
std::cout << (ctest->capacity()==test1->capacity())<< std::endl;
//Test size()
std::cout << (test1->size()==4)<< std::endl;
//Test length()
std::cout<<(test1->length()==4)<<std::endl;

//Test c_str()
char str1[] = {'T','o','t','o','\0'};
std::cout<<((strcmp(test1->c_str(),str1)==0))<<std::endl;

std::cout<<"Test operator=(char*)"<<std::endl;//Test operator=(char*)
*test1 = "bou";
std::cout<<((strcmp(test1->c_str(),"bou")==0))<<std::endl;
*test1= "baracuda";
std::cout<<((strcmp(test1->c_str(),"baracuda")==0))<<std::endl;
String test3="baudruche";
std::cout<<((strcmp(test3.c_str(),"baudruche")==0))<<std::endl;

std::cout<<"Test operator+(String)"<<std::endl;//Test operator+ String
String test4=test3+*test1;
std::cout<<(test4.length()==17)<< (test4.capacity()==17) <<std::endl;
std::cout<<((strcmp(test4.c_str(),"baudruchebaracuda")==0)) <<std::endl;

//Test max_size()
std::cout<<(test1->max_size()==100)<<std::endl;
std::cout<<(test2->max_size()==100)<<std::endl;

//Test clear()
ctest->clear() ;
std::cout<<(ctest->size()==0)<<std::endl;
std::cout<<((strcmp(ctest->c_str(),"")==0))<<std::endl;
//Test limitation size (Lms)
char c[]       ="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
String testLms1("");
testLms1=c;
std::cout<<(testLms1.size()==100)<<(testLms1.c_str()[99]=='a')<<(testLms1.c_str()[100]=='\0')<<std::endl;
testLms1.reserve(10000);
std::cout<<(testLms1.size()==100)<<(testLms1.c_str()[99]=='a')<<(testLms1.c_str()[100]=='\0')<<std::endl;
String* testLms2=new String(c);
std::cout<<(testLms2->size()==100)<<(testLms2->c_str()[99]=='a')<<(testLms2->c_str()[100]=='\0')<<std::endl;
String testLms3 = testLms1+*testLms2;
std::cout<<(testLms3.size()==100)<<(testLms3.c_str()[99]=='a')<<(testLms3.c_str()[100]=='\0')<<std::endl;
delete testLms2;

//Test operator=String
*test1= test3;
//Test operator=(char)
test3 = 'C' ;
std::cout<<test3.c_str()<<std::endl;
//Test operator+(char*)
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
String dctest ;
std::cout<<dctest.c_str()<<std::endl;
std::cout<<(dctest.size()==0)<<std::endl;


delete test1;
delete test2;
return 0;
}
