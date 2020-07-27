# ChonkyNumber
C++ easy to use big number class for integer arbitrary-precision arithmetic computation.

In ChonkyNumbers each mathematical operators have been overrided and can be used with other types like strings, char array, long long int, long int and int

There are not limits in using ChonkyNumber if not the memory or the computational time.

## Installation
To add ChonkyNumber to your C++ project, you can clone this repository or download the two single files and
and import them into your project.

## Usage
After importing the repo you can use chonky numbers by including the header:
    
    #include "path/ChonkyNumber.h"

### `Constructors`
To create a new ChonkyNumber there are a few constructors available.

    ChonkyNumber();              // Creates a new ChonkyNumber with value 0
    ChonkyNumber(std::string&);  // Creates a new ChonkyNumber with value based on a string reference
    ChonkyNumber(std::string&&); // Creates a new ChonkyNumber with value based on a temporary string
    ChonkyNumber(const char*);   // Creates a new ChonkyNumber with value based on a char array
    ChonkyNumber(long long int); // Creates a new ChonkyNumber with value based on a long long int
    ChonkyNumber(long int);      // Creates a new ChonkyNumber with value based on a long int
    ChonkyNumber(int);           // Creates a new ChonkyNumber with value based on a int

### `Declarations`
A ChonkyNumber can be declared by calling its constructor explicitly:

    ChonkyNumber x;                      //ChonkyNumber x declared with default constructor and value 0
    ChonkyNumber y("-382");              //ChonkyNumber y declared with value -382.
    ChonkyNumber z(std::string("184"));  //ChonkyNumber z declared with value 184.
    ChonkyNumber w(193938282897300000);  //ChonkyNumber w declared with value 193938282897300000.
    ChonkyNumber t(-900000);             //ChonkyNumber t declared with value -900000.
    x = t;                               //ChonkyNumber x with value -900000

Or Implicity with the = operator:

    ChonkyNumber x = "-382";               //ChonkyNumber x declared with value -382.
    ChonkyNumber y = std::string("184");   //ChonkyNumber y declared with value 184.
    ChonkyNumber z = 193938282897300000);  //ChonkyNumber z declared with value 193938282897300000.
    ChonkyNumber w = -900000;              //ChonkyNumber w declared with value -900000.
    
## Operator Overload
### `operator+(const ChonkyNumber&, const ChonkyNumber&)`

    ChonkyNumber x(-150), y("15");
    x + y; // -> ChonkyNumber(-135)
    x + 15; // -> ChonkyNumber(-135)
    ChonkyNumber(-150) + y; // -> ChonkyNumber(-135)
    ChonkyNumber(-150) + ChonkyNumber("15"); // -> ChonkyNumber(-135)

### `operator-(const ChonkyNumber&, const ChonkyNumber&)`

    ChonkyNumber x(150), y("-15");
    x - y; // -> ChonkyNumber(165)
    x - -15; // -> ChonkyNumber(165)
    ChonkyNumber(150) - y; // -> ChonkyNumber(165)
    ChonkyNumber(150) - ChonkyNumber("-15"); // -> ChonkyNumber(165)

### `operator*(const ChonkyNumber&, const ChonkyNumber&)`

    ChonkyNumber x(150), y("-15");
    x * y; // -> ChonkyNumber(-2.250)
    x * -15; // -> ChonkyNumber(-2.250)
    ChonkyNumber(150) * y; // -> ChonkyNumber(-2.250)
    ChonkyNumber(150) * ChonkyNumber("-15"); // -> ChonkyNumber(-2.250)

### `operator/(const ChonkyNumber&, const ChonkyNumber&)`

    ChonkyNumber x(150), y("-15");
    x / y; // -> ChonkyNumber(-10)
    x / -15; // -> ChonkyNumber(-10)
    ChonkyNumber(150) / y; // -> ChonkyNumber(-10)
    ChonkyNumber(150) / ChonkyNumber("-15"); // -> ChonkyNumber(-10)

### `operator^(const ChonkyNumber&, int)`
Raises the ChonkyNumber to the power of the exponent

    ChonkyNumber x(150);
    x ^ 3; // -> ChonkyNumber(3.375.000)
    
### `operator%(const ChonkyNumber&, int)`
Calculate the module of a ChonkyNumber by giving a module

    ChonkyNumber x(150);
    x % 3; // -> ChonkyNumber(0)
    
### `operators +=, -=, *=, /* (const ChonkyNumber&, const ChonkyNumber&)`
Those operations are similar to the previous one but does not return a new object, instead they modify the first parameter and return it's reference.
Those operations are preferred since no additional unused object is create

### `PREFIX operator++()`
Increment a ChonkyNumber and return a reference of it.

    ChonkyNumber x(150);
    ++x; // x = 151 and returns a reference of x
    
### `PREFIX operator--()`
Decrement a ChonkyNumber and return a reference of it.

    ChonkyNumber x(150);
    x--; // x = 149 and returns a copy of it

### `POSTFIX operator++(int)`
Increment a ChonkyNumber and return a copy of it. (use prefix whenever possible)

    ChonkyNumber x(150);
    x++; // x = 151 and returns a copy of it
    
### `POSTFIX operator--(int)`
Decrement a ChonkyNumber and return a copy of it. (use prefix whenever possible)

    ChonkyNumber x(150);
    x--; // x = 149 and returns a copy of it

## Credit
The ChonkyNumber class was created by [Ivan Lo Greco].
