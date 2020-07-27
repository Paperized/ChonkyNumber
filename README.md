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
    
## Mathematical Operator Overload
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
    
## Comparison Operators Overload
### `operator==(const ChonkyNumber&, const ChonkyNumber&)`
True if the first ChonkyNumber is equal to the second

    ChonkyNumber x(150), y("-15");
    x == y; // -> false
    x == -15; // -> false
    x == 150; // -> true
    ChonkyNumber(150) == ChonkyNumber("-15"); // -> false

### `operator>(const ChonkyNumber&, const ChonkyNumber&)`
True if the first ChonkyNumber is major to the second

    ChonkyNumber x(150), y("-15");
    x > y; // -> true
    x > -15; // -> true
    x > 150; // -> false
    ChonkyNumber(150) > ChonkyNumber("-15"); // -> true

### `operator<(const ChonkyNumber&, const ChonkyNumber&)`
True if the first ChonkyNumber is less then the second

    ChonkyNumber x(150), y("-15");
    x < y; // -> false
    x < -15; // -> false
    x < 150; // -> false
    ChonkyNumber(150) < ChonkyNumber("-15"); // -> false

### `operator>=(const ChonkyNumber&, const ChonkyNumber&)`
True if the first ChonkyNumber is major or equal to the second

    ChonkyNumber x(150), y("-15");
    x >= y; // -> true
    x >= -15; // -> true
    x >= 150; // -> true
    ChonkyNumber(150) >= ChonkyNumber("-15"); // -> true

### `operator<=(const ChonkyNumber&, const ChonkyNumber&)`
True if the first ChonkyNumber is less or equal of the second

    ChonkyNumber x(150), y("-15");
    x <= y; // -> false
    x <= -15; // -> false
    x <= 150; // -> true
    ChonkyNumber(150) <= ChonkyNumber("-15"); // -> false

## Methods
### `void ChangeValue(...) + 7 overloads`
Change the value of the ChonkyNumber instance.
If the value is not correct it will be set to "NaN" (Not a Number) and the flag m_IsNumber will be set to false.

    ChonkyNumber x(150), y("-15");
    x < y; --> false
    y.ChangeValue(151);
    x < y; --> true
    
Overloads:

	void ChangeValue(ChonkyNumber&);
    void ChangeValue(std::string& str);
	void ChangeValue(const char* c_arr);
	void ChangeValue(std::string&& str);
    void ChangeValue(long long int num);
	void ChangeValue(long int num);
	void ChangeValue(int num);

### `bool IsNaN()`
Return true if the ChonkyNumber doesn't contain a number.

    ChonkyNumber x(150), y("-1-5");
    x.IsNan(); // -> false
    y.IsNan(); --> true

### `bool IsEven()`
Return true if the ChonkyNumber is even.

    ChonkyNumber x(150), y("-15");
    x.IsEven(); // -> true
    y.IsEven(); --> false

### `bool IsOdd()`
Return true if the ChonkyNumber is odd.

    ChonkyNumber x(150), y("-15");
    x.IsOdd(); // -> false
    y.IsOdd(); --> true

### `bool IsPrime() const`
Return true if the ChonkyNumber is prime.

    ChonkyNumber x(150), y("-11");
    x.IsPrime(); // -> false
    y.IsPrime(); --> true
    
### `void SetAsIrregular()`
Set the current value as NaN and the flag m_IsNumber to false.

    ChonkyNumber x(150);
    x.IsNaN(); // -> false
    x.SetAsIrregular();
    y.IsNaN(); --> true
    
### `std::string AsString() const`
Get the string of a ChonkyNumber

    ChonkyNumber x(-150);
    x.AsString(); // -> "-150"
    
### `int DigitsSize() const`
Get the number of digits of a instance

    ChonkyNumber x(-15234324320);
    x.DigitsSize(); // -> 11
    
### `ChonkyNumber& Negate()`
Negate the current instance and return it's reference

    ChonkyNumber x(-15234324320);
    x.AsString(); // -> "-15234324320"
    x.Negate();
    x.AsString(); // -> "15234324320"
    
## Helper Static Functions
### `static bool IsNumber(std::string& str)`
Return true if the string is a number well formatted

    std::string& num = "-184743";
    ChonkyNumber::IsNumber(num); // -> true;
    std::string& num2 = "-18474<3";
    ChonkyNumber::IsNumber(num); // -> false;
    
### `static bool HasBiggerDigits(const ChonkyNumber& num1, const ChonkyNumber& num2)`
Basically return true if the first number its major of the second one ignoring their signs.

    std::string& num = "-184743";
    std::string& num2 = "-184742";
    //Implicit conversion from string to ChonkyNumber
    ChonkyNumber::HasBiggerDigits(num, num2); // -> true;
    
### `static bool HasBiggerOrEqualDigits(const ChonkyNumber& num1, const ChonkyNumber& num2)`
Basically return true if the first number its major or equal of the second one ignoring their signs.

    std::string& num = "-184743";
    std::string& num2 = "-184743";
    //Implicit conversion from string to ChonkyNumber
    ChonkyNumber::HasBiggerOrEqualDigits(num, num2); // -> true;

### Mathematical static functions
Those static functions are used under the hood for operation overloading, they do the same thing but in a different way more function driven then the operators:

Most of them are self explanatory, the last parameter (the pointer) its just a container in which store the output of the operation

	static void Add(ChonkyNumber&, ChonkyNumber&, ChonkyNumber*);
	static void AddAll(std::vector<ChonkyNumber>&, ChonkyNumber*);
	static void Subtract(ChonkyNumber&, ChonkyNumber&, ChonkyNumber*);
	static void Multiply(ChonkyNumber&, ChonkyNumber&, ChonkyNumber*);
	static void Divide(ChonkyNumber&, ChonkyNumber&, ChonkyNumber*);
	static void Pow(ChonkyNumber&, int, ChonkyNumber*);
	static void Module(ChonkyNumber&, int, ChonkyNumber*);

## Credit
The ChonkyNumber class was created by [Ivan Lo Greco].
