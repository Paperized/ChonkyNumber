#pragma once

#include <string>
#include <vector>

constexpr const char* IRREGULAR_OPERATION = "NaN";

//Check if the two ChonkyNumbers are not a number, if yes set the output as irregular and return
#define RETURN_IF_NAN_OPERANDS(num1, num2, output) if(!num1.m_IsNumber || !num2.m_IsNumber) \
													{ \
														output->SetAsIrregular(); \
														return; \
													}

//Check if it's not a number, if yes set the output as irregular and return
#define RETURN_IF_NAN_OPERAND(num1, output) if(!num1.m_IsNumber) \
												{ \
													output->SetAsIrregular(); \
													return; \
												}

/*
	BigNumber class to compute Integer arbitrary-precision math
*/
class ChonkyNumber
{
public:
	//Instantiate a ChonkyNumber with default value 0
	ChonkyNumber();
	//Instantiate a ChonkyNumber with a string
	ChonkyNumber(std::string& number);
	//Instantiate a ChonkyNumber with a string
	ChonkyNumber(std::string&&);
	//Instantiate a ChonkyNumber with a char array
	ChonkyNumber(const char*);
	//Instantiate a ChonkyNumber with a long long int
	ChonkyNumber(long long int);
	//Instantiate a ChonkyNumber with a long int
	ChonkyNumber(long int);
	//Instantiate a ChonkyNumber with a int
	ChonkyNumber(int);
	~ChonkyNumber();

	//Change the current value with another ChonkyNumber
	void ChangeValue(ChonkyNumber&);
	//Change the current value with a str
	inline void ChangeValue(std::string& str) { if (ChonkyNumber::IsNumber(str)) ChangeValue(str, true); else { std::string n = IRREGULAR_OPERATION; ChangeValue(n, true); } }
	//Change the current value with a char array
	inline void ChangeValue(const char* c_arr) { std::string str = c_arr; ChangeValue(c_arr); }
	//Change the current value with a char array
	inline void ChangeValue(std::string&& str) { ChangeValue(str); }
	//Change the current value with a long long int
	inline void ChangeValue(long long int num) { std::string str = std::to_string(num); ChangeValue(str, true); }
	//Change the current value with a long int
	inline void ChangeValue(long int num) { std::string str = std::to_string(num); ChangeValue(str, true); }
	//Change the current value with an int
	inline void ChangeValue(int num) { std::string str = std::to_string(num); ChangeValue(str, true); }
	
	//Return true if number
	inline bool IsNaN () { return !m_IsNumber; }
	//Return true if even
	inline bool IsEven() { return m_IsNumber && ((m_Number[m_Number.size() - 1] - 48) % 2 == 0); }
	//Return true if odd
	inline bool IsOdd() { return m_IsNumber && ((m_Number[m_Number.size() - 1] - 48) % 2 != 1); }
	//Return true if prime
	bool IsPrime() const;
	//Set the current value as irregular or NaN, usefull when computing an irregular operation
	void SetAsIrregular();
	//Stringify the current value
	std::string AsString() const;

	//Get the current value's digits size
	inline int DigitsSize() const { return m_Number.size(); }
	//Negate the current number and return a reference of it
	inline ChonkyNumber& Negate() { m_IsNegative = !m_IsNegative; return *this; }

	//Sum another ChonkyNumber and return a reference of the first
	ChonkyNumber& operator+=(const ChonkyNumber& num);
	//Subtract another ChonkyNumber and return a reference of the first
	ChonkyNumber& operator-=(const ChonkyNumber& num);
	//Multiply another ChonkyNumber and return a reference of the first
	ChonkyNumber& operator*=(const ChonkyNumber& num);
	//Divide another ChonkyNumber and return a reference of the first
	ChonkyNumber& operator/=(const ChonkyNumber& num);

	//Prefix increment, returns a reference of the number
	ChonkyNumber& operator++();
	//Prefix decrement, returns a reference of the number
	ChonkyNumber& operator--();
	//Postfix increment, returns a new value of the number
	ChonkyNumber operator++(int);
	//Postfix decrement, returns  a new value of the number
	ChonkyNumber operator--(int);

	//Equal compare two ChonkyNumber
	friend inline bool operator==(const ChonkyNumber& num1, const ChonkyNumber& num2) { return num1.m_Number.compare(num2.m_Number) == 0 && num1.m_IsNegative == num2.m_IsNegative; }
	//Major compare two ChonkyNumber
	friend inline bool operator>(const ChonkyNumber& num1, const ChonkyNumber& num2)  { return (num1.m_IsNegative <= num2.m_IsNegative) && ChonkyNumber::HasBiggerDigits(num1, num2); }
	//Less compare two ChonkyNumber
	friend inline bool operator<(const ChonkyNumber& num1, const ChonkyNumber& num2)  { return (num1.m_IsNegative >= num2.m_IsNegative) && ChonkyNumber::HasBiggerDigits(num2, num1); }
	//Major or equals compare two ChonkyNumber
	friend inline bool operator>=(const ChonkyNumber& num1, const ChonkyNumber& num2) { return (num1.m_IsNegative <= num2.m_IsNegative) && ChonkyNumber::HasBiggerOrEqualDigits(num1, num2); }
	//Less or equals compare two ChonkyNumber
	friend inline bool operator<=(const ChonkyNumber& num1, const ChonkyNumber& num2) { return (num1.m_IsNegative >= num2.m_IsNegative) && ChonkyNumber::HasBiggerOrEqualDigits(num1, num2); }

	//Sum two ChonkyNumber and return a new value
	friend ChonkyNumber operator+(const ChonkyNumber&, const ChonkyNumber&);
	//Subtract two ChonkyNumber and return a new value
	friend ChonkyNumber operator-(const ChonkyNumber&, const ChonkyNumber&);
	//Multiply two ChonkyNumber and return a new value
	friend ChonkyNumber operator*(const ChonkyNumber&, const ChonkyNumber&);
	//Divide two ChonkyNumber and return a new value
	friend ChonkyNumber operator/(const ChonkyNumber&, const ChonkyNumber&);
	//Pow a ChonkyNumber with it's exponent and return a new value
	friend ChonkyNumber operator^(const ChonkyNumber&, int);
	//Module a ChonkyNumber with it's module and return a new value
	friend ChonkyNumber operator%(const ChonkyNumber&, int);

	friend inline std::ostream& operator<<(std::ostream& os, const ChonkyNumber& num) { os << num.AsString(); return os; }

	//Check if the number (sign ignored) of first ChonkyNumber it's bigger than the second
	inline static bool HasBiggerDigits(const ChonkyNumber& num1, const ChonkyNumber& num2) { return (num1.DigitsSize() > num2.DigitsSize()) || (num1.DigitsSize() == num2.DigitsSize() && num1.m_Number.compare(num2.m_Number) > 0); }
	//Check if the number (sign ignored) of first ChonkyNumber it's bigger or equals than the second
	inline static bool HasBiggerOrEqualDigits(const ChonkyNumber& num1, const ChonkyNumber& num2) { return (num1.DigitsSize() > num2.DigitsSize()) || (num1.DigitsSize() == num2.DigitsSize() && num1.m_Number.compare(num2.m_Number) >= 0); }

	//Add two ChonkyNumber and output the result to the pointer argument
	static void Add(ChonkyNumber&, ChonkyNumber&, ChonkyNumber*);
	//Add all ChonkyNumber inside a vector and output the result to the pointer argument
	static void AddAll(std::vector<ChonkyNumber>&, ChonkyNumber*);
	//Subtract two ChonkyNumber and output the result to the pointer argument
	static void Subtract(ChonkyNumber&, ChonkyNumber&, ChonkyNumber*);
	//Multiply two ChonkyNumber and output the result to the pointer argument
	static void Multiply(ChonkyNumber&, ChonkyNumber&, ChonkyNumber*);
	//Divide two ChonkyNumber and output the result to the pointer argument
	static void Divide(ChonkyNumber&, ChonkyNumber&, ChonkyNumber*);
	//Pow a ChonkyNumber by it's exponent and output the result to the pointer argument
	static void Pow(ChonkyNumber&, int, ChonkyNumber*);
	//Module a ChonkyNumber by it's module and output the result to the pointer argument
	static void Module(ChonkyNumber&, int, ChonkyNumber*);
	//Check if the string it's an actual integer number
	static bool IsNumber(std::string& str);

private:
	//Assign the string value as the number of this ChonkyNumber, bool value ignores any sign change
	void ChangeValue(std::string&, bool);

private:
	//String rappresentation of the number (without sign)
	std::string m_Number;
	//Sign of the number
	bool m_IsNegative;
	//Check if it's an actual number
	bool m_IsNumber;
};
