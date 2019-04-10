#include <iostream>
#include <string.h>
#include"String.h"
int main(){


String* test1= new String(20);
const char* s="Character sequence test";
String* test2 = new String(s);
std::cout<<"Test Constructor(c_str) : "<<std::endl;
std::cout<<(strcmp("Character sequence test",test2->c_str())==0)<<std::endl;


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

//Test default Constructor
std::cout << "Default Constructor test" << std::endl;
String dctest ;
std::cout<<(strcmp(dctest.c_str(),"")==0)<<std::endl;
std::cout<<(dctest.size()==0)<<std::endl;

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
std::cout<<"Test method length() : "<<std::endl;
std::cout<<(test1->length()==4)<<std::endl;

//Test c_str()
std::cout << "C_str Test" << std::endl;
String test_str1 ;
String test_str2(" World") ;
char str1[] = "" ;
char str2[] = " World" ;
std::cout<<((strcmp(test_str1.c_str(),str1)==0))<<std::endl;
std::cout<<((strcmp(test_str2.c_str(),str2)==0))<<std::endl;

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
std::cout<<"Test method max_size() : "<<std::endl;
std::cout<<(test1->max_size()==100)<<std::endl;
std::cout<<(test2->max_size()==100)<<std::endl;

//Test clear()
std::cout << "Clear Test" << std::endl;
String test_cle ;
String test_cle2("Python") ;
test_cle.clear() ;
test_cle2.clear() ;
std::cout<<(test_cle.size()==0)<<std::endl;
std::cout<<((strcmp(test_cle.c_str(),"")==0))<<std::endl;
std::cout<<(test_cle2.size()==0)<<std::endl;
std::cout<<((strcmp(test_cle2.c_str(),"")==0))<<std::endl; 

//Test limitation size
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
std::cout<<"Test operator =(String)"<<std::endl;
*test1= test3;
std::cout<<(strcmp(test1->c_str(),test3.c_str())==0)<<std::endl;

//Test operator=(char)
std::cout << "Operator= (char) Test" << std::endl;
String test_ope1 ;
String test_ope2 ;
char char1 = 'C' ;
char char2 = '+' ;
test_ope1 = char1;
test_ope2 = char2;
std::cout<<(strcmp(test_ope1.c_str(),"C")==0)<<std::endl;
std::cout<<(strcmp(test_ope2.c_str(),"+")==0)<<std::endl;

//Test operator+(char*)
std::cout << "Operator+ (char*) Test" << std::endl;
String test_ope3 ;
String test_ope4 ;
String test_ope5 ;
test_ope3 = "++" + test_ope1 ;
test_ope4 = test_ope1 + "++" ;
test_ope5 = test_ope1 + "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" ;
std::cout<<(strcmp(test_ope3.c_str(),"++C")==0)<<std::endl;
std::cout<<(strcmp(test_ope4.c_str(),"C++")==0)<<std::endl;
std::cout<<(test_ope5.max_size()==100)<<std::endl;

//Test operator+(char)
std::cout<<"Test operator +(char)"<<std::endl;

String test_operator_char=test_ope1+'+' ;
std::cout<<(strcmp(test_operator_char.c_str(),"C+")==0)<<std::endl;

//Test method resize()
std::cout<<"Test method resize()"<<std::endl;
String test_res1("C") ;
String test_res2("C") ;
test_res1.resize(11,'+');
std::cout<<(strcmp(test_res1.c_str(),"C++++++++++")==0)<<std::endl;
test_res2.resize(3,'+');
std::cout<<(strcmp(test_res2.c_str(),"C++")==0)<<std::endl;

delete test1;
delete test2;


return 0;
}
