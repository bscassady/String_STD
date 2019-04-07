#include<cstddef>

#ifndef STRING_ 
#define STRING_

class String{

  friend String operator+ (const String& lhs, const String& rhs);
  friend String operator+ (const char*   lhs, const String& rhs);//Returns a newly constructed string object with its value being the concatenation of the characters in lhs followed by those of rhs.
  public :
  //Constructors
  String();

  String(size_t Arbitrary_value_of_capacity);// Trivial Constructor with Arbitrary_value_of_capacity as parameter because we don't know how to get it yet
  String(const char* s);

  String (const String& str);//Copy constructor - constructs a copy of str.

  //Destructor
  ~String();//Destroys the string object. This deallocates all the storage capacity allocated by the string using its allocator.

  //Operator
  String& operator= (const char* s);//Assigns a new value to the string, replacing its current contents with a pointer to a null-terminated sequence of characters passed as  parameter. The sequence is copied as the new value for the string.
  String& operator= (const String& s);//Assigns a new value to the string, replacing its current contents with the contents of another String passed as parameter.
  String& operator= (char c);//The string value is set to a single copy of this character (the string length becomes 1).
  //getters
  size_t capacity();//Returns the size of the storage space currently allocated for the string, expressed in terms of bytes. This capacity is not necessarily equal to the string length. It can be equal or greater, with the extra space allowing the object to optimize its operations when new characters are added to the string.

  size_t size() const;//Returns the length of the string, in terms of bytes.

  size_t length() const;

  const char* c_str() const; //Returns a pointer to an array that contains a null-terminated sequence of characters
  
  size_t max_size() const;//Returns the maximum length of the string, in terms of bytes. Arbitrarily equals 100.

  void clear();//Erases the contents of the string, which becomes an empty string.

  //setters
  
  //methods
  bool empty() const;//Returns whether the string is empty (i.e. whether its length is 0).

  
  void reserve (size_t n);//Requests that the string capacity be adapted to a planned change in size to a length of up to n characters. If n is greater than the current string capacity, the function causes the container to increase its capacity to n characters (or greater). In all other cases, it is taken as a non-binding request to shrink the string capacity: the container implementation is free to optimize otherwise and leave the string with a capacity greater than n.

  void resize(size_t n, char c);//Changes the size of the str_ attribute to a size n passed as parameter. if n is greater than the current size, the character c is appended the adequate the number of time. if n is less, a troncature of the first n elements of str_ is affected to str_.
  
  protected : 
  //attributes
  static size_t MAX_SIZE_;
  size_t size_;
  size_t capacity_;
  char* str_;
  
  
    
    


};
String operator+ (const String& lhs, const String& rhs);
#endif //STRING_
