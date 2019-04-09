#include"String.h"
#include<cstddef>

size_t String::MAX_SIZE_=100;

String::String(){
  size_ = 0 ;
  capacity_ = 0 ;
  str_= new char[1];
  str_[0]='\0' ; 
}

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
  if(size_>MAX_SIZE_){
  size_=MAX_SIZE_;
  }
  capacity_ = size_;
  str_ = new char[capacity_+1];
  for(unsigned int i =0;i<size_;++i){
    str_[i]=s[i];
  }
  str_[size_]='\0'; 
  
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
  if(n>MAX_SIZE_){
  n=MAX_SIZE_;
  }
  if (capacity_< n){
    char* strbis=str_;
    str_=new char[n+1];
    for (size_t i=0;i<size_;++i){
      str_[i]=strbis[i];    
    }
    str_[size_]='\0'; 
    delete[] strbis;
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

void String::resize(size_t n, char c){
  if(n>MAX_SIZE_){
    n=MAX_SIZE_;
  }  
  if(n>size_){
    reserve(n+1);
    for(size_t i =size_;i<n;++i){
      str_[i]=c;
    }
    str_[n]='\0';
  }
  else{
   
    str_[n]='\0'; 
    
    size_=n;
  }
}    
      

String& String::operator= (const char* s){
  size_ = 0;
  while(s[size_]!='\0'){
    ++size_;
  }
  if(size_>MAX_SIZE_){
  size_=MAX_SIZE_;
  }
  if (capacity_<size_){
    capacity_=size_;
    delete[] str_;
    str_=new char[capacity_+1];
  }
  for(unsigned int i =0;i<size_;++i){
    str_[i]=s[i];
  }
  str_[size_]='\0'; 
  

  return *this;
}


String operator+ (const String& lhs, const String& rhs){
  String str;
  str.size_=lhs.size_+rhs.size_;
  if(str.size_>str.MAX_SIZE_){
  str.size_=str.MAX_SIZE_;
  }
  str.capacity_=lhs.size_+rhs.size_;
  delete[] str.str_;
  str.str_=new char[str.capacity_+1];
  for(unsigned int i =0;i<lhs.size_;++i){
    str.str_[i]=lhs.str_[i];
  }
  for(unsigned int i =lhs.size_;i<str.size_;++i){
    str.str_[i]=rhs.str_[i-lhs.size_];
  }
  str.str_[str.size_]='\0';
  return str;
}

String& String::operator= (const String& s){
  size_=0;
  while(s.str_[size_]!='\0'){
    ++size_;
  }
  if(size_>MAX_SIZE_){
  size_=MAX_SIZE_;
  }
  if(capacity_<size_){
    capacity_=size_;
    delete[] str_;
    str_=new char[capacity_+1];
  }
  for(size_t i =0;i<size_;++i){
    str_[i]=s.str_[i];
  }
  str_[size_]='\0'; 

  
  return *this;
}

String& String::operator= (char c){
  if (size_ == 0) {
    delete [] str_ ;
    capacity_ = 1 ;
    str_= new char[capacity_ + 1];
  }
  str_[0] = c ;
  str_[1] = '\0' ;
  size_ = 1 ;
  return *this;
}

String operator+ (const char* lhs, const String& rhs){
  String new_string ;
  String lhs_str = lhs ;
  new_string.size_ = lhs_str.size_ + rhs.size_;
  if(new_string.size_ > new_string.MAX_SIZE_){
  new_string.size_ = new_string.MAX_SIZE_;
  }
  new_string.capacity_ = lhs_str.size_ + rhs.size_;
  delete[] new_string.str_;
  new_string.str_ = new char[new_string.capacity_ + 1];
  for(size_t i = 0 ; i < lhs_str.size_ ; ++i){
    new_string.str_[i] = lhs_str.str_[i];
  }
  for(size_t i =lhs_str.size_ ; i < new_string.size_ ; ++i){
    new_string.str_[i] = rhs.str_[i-lhs_str.size_];
  }
  new_string.str_[new_string.size_]= '\0';
  return new_string ;
}


String operator+ (const String& lhs,const char rhs ){
  String str_rhs;
  str_rhs = rhs; 
  return lhs+str_rhs;
} 
  

String operator+ (const String& lhs, const char* rhs){
  String new_string ;
  String rhs_str = rhs ;
  new_string.size_ = lhs.size_ + rhs_str.size_;
  if(new_string.size_ > new_string.MAX_SIZE_){
  new_string.size_ = new_string.MAX_SIZE_;
  }
  new_string.capacity_ = lhs.size_ + rhs_str.size_;
  delete[] new_string.str_;
  new_string.str_ = new char[new_string.capacity_ + 1];
  for(size_t i = 0 ; i < lhs.size_ ; ++i){
    new_string.str_[i] = lhs.str_[i];
  }
  for(size_t i =lhs.size_ ; i < new_string.size_ ; ++i){
    new_string.str_[i] = rhs_str.str_[i-lhs.size_];
  }
  new_string.str_[new_string.size_]= '\0';
  return new_string ;
}















