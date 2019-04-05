#include"String.h"
#include<cstddef>

size_t String::MAX_SIZE_=100;

String::String(size_t Arbitrary_value_of_capacity){
  capacity_=Arbitrary_value_of_capacity;
  size_ = 4;
  str_=new char[capacity_+1];
  str_[0]='T';
  str_[1]='o';
  str_[2]='t';
  str_[3]='o';
  str_[4]='\0';
}

String::String(const char* s){
  size_ = 0;
  while(s[size_]!='\0'){
    ++size_;
  }
  capacity_ = size_;
  str_ = new char[capacity_+1];
  for(unsigned int i =0;i<=size_;++i){
    str_[i]=s[i];
  }
}

String::String(const String& str){
  size_ = str.size_ ;
  capacity_ = str.capacity_ ;
  str_ = new char[capacity_ + 1] ;
  for (size_t i = 0 ; i <= size_ ; ++i){
      str_[i]=str.str_[i] ;    
  }
}

String::~String(){
  delete[] str_; 
}

void String::reserve (size_t n){
  if (capacity_< n){
    char* strbis=str_;
    str_=new char[n+1];
    for (size_t i=0;i<=size_;++i){
      str_[i]=strbis[i];    
    }
    delete strbis;
    capacity_=n;    
  }
  
}

size_t String::capacity(){
  return capacity_;
}
bool String::empty() const{
  return size_==0;
}


size_t String::size() const{
  return size_;
}

size_t String::length() const{
  return size_;
}


const char* String::c_str() const{
  return str_ ;
}

size_t String::max_size() const{
  return MAX_SIZE_;
}

void String::clear(){
  str_[0]='\0';
  size_ = 0 ;  
}

String& String::operator= (const char* s){
  size_ = 0;
  while(s[size_]!='\0'){
    ++size_;
  }
  if (capacity_<size_){
    capacity_=size_;
    str_=new char[capacity_+1];
  }
  for(unsigned int i =0;i<=size_;++i){
    str_[i]=s[i];
  }  
  

  return *this;
}

String& String::operator= (const String& s){
  size_=0;
  while(s.str_[size_]!='\0'){
    ++size_;
  }
  if(capacity_<size_){
    capacity_=size_;
    str_=new char[capacity_+1];
  }
  for(size_t i =0;i<=size_;++i){
    str_[i]=s.str_[i];
  }
  
  return *this;
}














