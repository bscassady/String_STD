#include"String.h"
#include<cstddef>

size_t String::MAX_SIZE_=100;

  /**************/
 /*CONSTRUCTORS*/
/**************/

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
    ++size_;//Allows to set the size of str_ to the size of s.
  }
  if(size_>MAX_SIZE_){
  size_=MAX_SIZE_;//This line keeps the String to have a size greater than MAX_SIZE_
  }
  capacity_ = size_;
  str_ = new char[capacity_+1];
  for(unsigned int i =0;i<size_;++i){
    str_[i]=s[i];   //the loop fills the str_ array with the characters of s.
  }
  str_[size_]='\0'; 
  
}

String::String(const String& str){
  size_ = str.size_ ;//Sets the current String size_ to the size of the String passed as parameter.
  capacity_ = str.capacity_ ;
  str_ = new char[capacity_ + 1] ;
  for (size_t i = 0 ; i <= size_ ; ++i){
      str_[i]=str.str_[i] ;    //Sets the current element's str_ attribute to the values of the str_ attribute of the String passed as parameter.
  }
}

String::~String(){
  delete[] str_; 
}

  /*********/
 /*GETTERS*/
/*********/

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

  /*********/
 /*METHODS*/
/*********/

void String::reserve (size_t n){
  if(n>MAX_SIZE_){
  n=MAX_SIZE_;//This line keeps the String to have a size greater than MAX_SIZE_
  }
  if (capacity_< n){
    char* strbis=str_;//We create a temporary char* with the content of str_ in order to copy them later.
    str_=new char[n+1];
    for (size_t i=0;i<size_;++i){
      str_[i]=strbis[i];   //The content of the strbis is copied in a newly created str_ with the adequate capacity_.
    }
    str_[size_]='\0'; 
    delete[] strbis;//The temporary array is deleted to avoid memory leak.
    capacity_=n;    
  }
  
}

void String::clear(){
  str_[0]='\0';
  size_ = 0 ;  
}

void String::resize(size_t n, char c){
  if(n>MAX_SIZE_){
    n=MAX_SIZE_;//This line keeps the String to have a size greater than MAX_SIZE_
  }  
  if(n>size_){
    reserve(n+1);//first the capacity_ is set to be greater than the new size_
    for(size_t i =size_;i<n;++i){
      str_[i]=c; //All elements in str_ between the previous size and the new are set to the char c.
    }
    str_[n]='\0';//The array is null-terminated
  }
  else{
   
    str_[n]='\0'; //The previous str_ is troncated by the null char.
    
    
  }
  size_=n;//size_ is set to its new value.
} 

   
  /***********/
 /*OPERATORS*/
/***********/

//operator=

String& String::operator= (const char* s){
  size_ = 0;
  while(s[size_]!='\0'){
    ++size_;//The size_ is set to the size of the char*.
  }
  if(size_>MAX_SIZE_){
  size_=MAX_SIZE_;//This line keeps the String to have a size greater than MAX_SIZE_.
  }
  if (capacity_<size_){
    capacity_=size_;
    delete[] str_;
    str_=new char[capacity_+1];//if the capacity is not big enough, it is set to be
  }
  for(unsigned int i =0;i<size_;++i){
    str_[i]=s[i];
  }
  str_[size_]='\0'; 
  

  return *this;
}




String& String::operator= (const String& s){
  size_=0;
  while(s.str_[size_]!='\0'){
    ++size_; //the loop sets size_ to the size_ of the string passed as parameter.
  }
  if(size_>MAX_SIZE_){
  size_=MAX_SIZE_;//size_ cannot be greater than MAX_SIZE_
  }
  if(capacity_<size_){
    capacity_=size_;
    delete[] str_;//If the capacity is not big enough, the string is replaced by a new one with the adequate capacity
    str_=new char[capacity_+1];
  }
  for(size_t i =0;i<size_;++i){
    str_[i]=s.str_[i];//str_ of the current element is filled with the content of the str_ attribute of the String in parameter.
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
  str_[0] = c ;//same process than with the char* but with a single char, so no need for a loop.
  str_[1] = '\0' ;
  size_ = 1 ;
  return *this;
}

//operator+

String operator+ (const String& lhs, const String& rhs){
  String str;
  str.size_=lhs.size_+rhs.size_;//str is a new String with a size_ equal to the sum of both parameters' size_ attributes.
  if(str.size_>str.MAX_SIZE_){
  str.size_=str.MAX_SIZE_;//size_ cannot be greater than MAX_SIZE_.
  }
  str.capacity_=lhs.size_+rhs.size_;
  delete[] str.str_;//str.str_ was an empty array. 
  str.str_=new char[str.capacity_+1];//Now str.str_ has the adequate capacity_
  for(unsigned int i =0;i<lhs.size_;++i){
    str.str_[i]=lhs.str_[i];//we first add the content of lhs' str_ attribute
  }
  for(unsigned int i =lhs.size_;i<str.size_;++i){
    str.str_[i]=rhs.str_[i-lhs.size_];//then we append rhs'
  }
  str.str_[str.size_]='\0';
  return str;
}

String operator+ (const char* lhs, const String& rhs){
  String new_string ;
  String lhs_str = lhs ;//the char* is converted into a String
  new_string.size_ = lhs_str.size_ + rhs.size_;//Use of the +operato(string)
  if(new_string.size_ > new_string.MAX_SIZE_){
  new_string.size_ = new_string.MAX_SIZE_;
  }
  new_string.capacity_ = lhs_str.size_ + rhs.size_;//the capacity is set to an adequate one 
  delete[] new_string.str_;
  new_string.str_ = new char[new_string.capacity_ + 1];//we erase the previous str_ then replace it with one with adequate size_.
  for(size_t i = 0 ; i < lhs_str.size_ ; ++i){
    new_string.str_[i] = lhs_str.str_[i];//we first add the content of lhs' str_ attribute
  }
  for(size_t i =lhs_str.size_ ; i < new_string.size_ ; ++i){
    new_string.str_[i] = rhs.str_[i-lhs_str.size_];//then we append rhs'
  }
  new_string.str_[new_string.size_]= '\0';
  return new_string ;
}



  

String operator+ (const String& lhs, const char* rhs){//the same as above but the other way around.
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

String operator+ (const String& lhs,const char rhs ){
  String str_rhs;//default constructor
  str_rhs = rhs; //Use of the the =operator(char)
  return lhs+str_rhs;//Use of the +operator(string)
} 













