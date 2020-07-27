#include "ChonkyNumber.h"

#include <iostream>
#include <ostream>

ChonkyNumber::ChonkyNumber() : m_IsNegative(false), m_IsNumber(true)
{
	m_Number = std::string("0");
}

ChonkyNumber::ChonkyNumber(const char* number) : m_IsNegative(false), m_IsNumber(true)
{
	std::string number_str = number;
	ChangeValue(number_str);
}

ChonkyNumber::ChonkyNumber(std::string& number) : m_IsNegative(false), m_IsNumber(true)
{
	ChangeValue(number);
}

ChonkyNumber::ChonkyNumber(std::string&& number) : m_IsNegative(false), m_IsNumber(true)
{
	ChangeValue(number);
}

ChonkyNumber::ChonkyNumber(long long int num) : m_IsNegative(false), m_IsNumber(true)
{
	std::string number = std::to_string(num);
	ChangeValue(number, true);
}

ChonkyNumber::ChonkyNumber(long int num) : m_IsNegative(false), m_IsNumber(true)
{
	std::string number = std::to_string(num);
	ChangeValue(number, true);
}

ChonkyNumber::ChonkyNumber(int num) : m_IsNegative(false), m_IsNumber(true)
{
	std::string number = std::to_string(num);
	ChangeValue(number, true);
}

ChonkyNumber::~ChonkyNumber()
{

}

void ChonkyNumber::ChangeValue(std::string& value, bool check_sign)
{
	if (this->m_IsNumber)
	{
		if (value == IRREGULAR_OPERATION)
		{
			this->m_Number = IRREGULAR_OPERATION;
			this->m_IsNumber = false;
			return;
		}
	}

	if (value != IRREGULAR_OPERATION)
	{
		this->m_IsNumber = true;
		if (value.size() == 0 || value[0] == '0')
		{
			m_IsNegative = false;
			m_Number = "0";
		}
		else
		{
			bool has_sign = value[0] == '-';
			if (check_sign)
				m_IsNegative = has_sign;

			m_Number = has_sign ? &value[1] : value;
		}
	}
}

void ChonkyNumber::ChangeValue(ChonkyNumber& value)
{
	m_Number = value.m_Number;
	m_IsNegative = value.m_IsNegative;
	m_IsNumber = value.m_IsNumber;
}

bool ChonkyNumber::IsPrime() const
{
	if (ChonkyNumber::HasBiggerOrEqualDigits(3, *this))
		return ChonkyNumber::HasBiggerOrEqualDigits(*this, 1);
	else if (*this % 2 == 0 || *this % 3 == 0)
		return false;

	int i = 5;
	while (ChonkyNumber::HasBiggerOrEqualDigits(*this, i * i))
	{
		if (*this % i == 0 || *this % (i + 2) == 0)
			return false;
		
		i = i + 6;
	}

	return true;
}

void ChonkyNumber::SetAsIrregular()
{
	this->m_Number = IRREGULAR_OPERATION;
	this->m_IsNumber = false;
}

std::string ChonkyNumber::AsString() const
{
	std::string str;
	if (this->m_IsNumber && this->m_IsNegative && this->m_Number[0] != '0')
		str += "-";

	str += m_Number;
	return str;
}

ChonkyNumber& ChonkyNumber::operator+=(const ChonkyNumber& num)
{
	ChonkyNumber::Add(*this, (ChonkyNumber&)num, this);
	return *this;
}

ChonkyNumber& ChonkyNumber::operator-=(const ChonkyNumber& num)
{
	ChonkyNumber::Subtract(*this, (ChonkyNumber&)num, this);
	return *this;
}

ChonkyNumber& ChonkyNumber::operator*=(const ChonkyNumber& num)
{
	ChonkyNumber::Multiply(*this, (ChonkyNumber&)num, this);
	return *this;
}

ChonkyNumber& ChonkyNumber::operator/=(const ChonkyNumber& num)
{
	ChonkyNumber::Divide(*this, (ChonkyNumber&)num, this);
	return *this;
}

ChonkyNumber& ChonkyNumber::operator++()
{
	ChonkyNumber unit = "1";
	ChonkyNumber::Add(*this, unit, this);
	return *this;
}

ChonkyNumber& ChonkyNumber::operator--()
{
	ChonkyNumber unit = "1";
	ChonkyNumber::Subtract(*this, unit, this);
	return *this;
}

ChonkyNumber ChonkyNumber::operator++(int)
{
	ChonkyNumber unit = "1";
	ChonkyNumber::Add(*this, unit, this);
	return *this;
}

ChonkyNumber ChonkyNumber::operator--(int)
{
	ChonkyNumber unit = "1";
	ChonkyNumber::Subtract(*this, unit, this);
	return *this;
}

ChonkyNumber operator+(const ChonkyNumber& num1, const ChonkyNumber& num2)
{
	ChonkyNumber res;
	ChonkyNumber::Add((ChonkyNumber&)num1, (ChonkyNumber&)num2, &res);
	return res;
}

ChonkyNumber operator-(const ChonkyNumber& num1, const ChonkyNumber& num2)
{
	ChonkyNumber res;
	ChonkyNumber::Subtract((ChonkyNumber&)num1, (ChonkyNumber&)num2, &res);
	return res;
}

ChonkyNumber operator/(const ChonkyNumber& num1, const ChonkyNumber& num2)
{
	ChonkyNumber res;
	ChonkyNumber::Divide((ChonkyNumber&)num1, (ChonkyNumber&)num2, &res);
	return res;
}

ChonkyNumber operator*(const ChonkyNumber& num1, const ChonkyNumber& num2)
{
	ChonkyNumber res;
	ChonkyNumber::Multiply((ChonkyNumber&)num1, (ChonkyNumber&)num2, &res);
	return res;
}

ChonkyNumber operator^(const ChonkyNumber& num, int exp)
{
	ChonkyNumber res;
	ChonkyNumber::Pow((ChonkyNumber&)num, exp, &res);
	return res;
}

ChonkyNumber operator%(const ChonkyNumber& num, int mod)
{
	ChonkyNumber res;
	ChonkyNumber::Module((ChonkyNumber&)num, mod, &res);
	return res;
}

void ChonkyNumber::AddAll(std::vector<ChonkyNumber>& nums, ChonkyNumber* output)
{
	if (nums.size() == 0)
	{
		std::string r = "0";
		output->ChangeValue(r, false);
		return;
	}

	output->ChangeValue(nums.at(0));

	for (unsigned int i = 1; i < nums.size(); ++i)
	{
		Add(*output, nums.at(i), output);
	}
}

void ChonkyNumber::Add(ChonkyNumber& num1, ChonkyNumber& num2, ChonkyNumber* output)
{
	RETURN_IF_NAN_OPERANDS(num1, num2, output);

	if (num1.m_IsNegative && !num2.m_IsNegative)
	{
		ChonkyNumber::Subtract(num2, num1.Negate(), output);
		num1.Negate();
		return;
	}
	else if(num2.m_IsNegative && !num1.m_IsNegative){
		ChonkyNumber::Subtract(num1, num2.Negate(), output);
		num2.Negate();
		return;
	}

	std::string sum;
	int x = num1.DigitsSize() - 1, y = num2.DigitsSize() - 1, carry = 0;

	while (x >= 0 && y >= 0)
	{
		int curr = num1.m_Number.at(x) - 48;
		int curr2 = num2.m_Number.at(y) - 48;
		int tot = curr + curr2 + carry;
		carry = tot > 9;

		sum.insert(sum.begin(), (tot % 10) + 48);
		--x;
		--y;
	}

	ChonkyNumber* remaining;
	int continue_at;

	if (x == -1 || y == -1)
	{
		if (x == -1)
		{
			remaining = &num2;
			continue_at = y;
		}
		else
		{
			remaining = &num1;
			continue_at = x;
		}

		while (continue_at >= 0)
		{
			int curr = remaining->m_Number.at(continue_at) - 48;
			int tot = curr + carry;
			carry = tot > 9;

			sum.insert(sum.begin(), (tot % 10) + 48);
			--continue_at;
		}
	}

	if (carry)
		sum.insert(sum.begin(), '1');

	output->ChangeValue(sum);
	output->m_IsNegative = num1.m_IsNegative && num2.m_IsNegative;
}

void ChonkyNumber::Subtract(ChonkyNumber& num1, ChonkyNumber& num2, ChonkyNumber* output)
{
	RETURN_IF_NAN_OPERANDS(num1, num2, output);
	ChonkyNumber* n1, * n2;

	if (num1.m_IsNegative && num2.m_IsNegative)
		if (ChonkyNumber::HasBiggerDigits(num2, num1))
		{
			n1 = &num2;
			n2 = &num1;
		}
		else // num1 > num2
		{
			n1 = &num1;
			n2 = &num2;
			output->Negate();
		}
	else if (!num1.m_IsNegative && !num2.m_IsNegative)
		if (ChonkyNumber::HasBiggerDigits(num2, num1))
		{
			n1 = &num2;
			n2 = &num1;
			output->Negate();
		}
		else
		{
			n1 = &num1;
			n2 = &num2;
		}
	else
	{
		ChonkyNumber::Add(num1, num2.Negate(), output);
		num2.Negate();
		return;
	}

	std::string sum;
	int x = n1->DigitsSize() - 1, y = n2->DigitsSize() - 1, less = 0;
	int zero_sequence_count = 0;

	while (x >= 0 && y >= 0)
	{
		int curr1 = n1->m_Number.at(x) - 48;
		int curr2 = n2->m_Number.at(y) - 48;
		int tot;

		if (less)
		{
			if (curr1 == 0)
				curr1 = 9;
			else
			{
				curr1 -= 1;
				less = 0;
			}
		}

		tot = curr1 - curr2;

		if (tot < 0)
		{
			tot += 10;
			less = true;
			zero_sequence_count = 0;
		}
		else
		{
			if (tot == 0)
				++zero_sequence_count;
			else
				zero_sequence_count = 0;
		} 

		sum.insert(sum.begin(), (tot % 10) + 48);
		--x;
		--y;
	}

	while (x >= 0)
	{
		int curr = n1->m_Number.at(x) - 48;

		if (less)
		{
			if (curr == 0)
			{
				curr = 9;
			}
			else
			{
				curr -= 1;
				less = 0;
			}
		}

		if (curr == 0)
			++zero_sequence_count;
		else
			zero_sequence_count = 0;

		sum.insert(sum.begin(), curr + 48);
		--x;
	}

	if (zero_sequence_count > 0)
	{
		sum = sum.substr(zero_sequence_count, sum.size() - zero_sequence_count);
	}

	output->ChangeValue(sum, false);
}

void ChonkyNumber::Multiply(ChonkyNumber& num1, ChonkyNumber& num2, ChonkyNumber* output)
{
	RETURN_IF_NAN_OPERANDS(num1, num2, output);

	std::vector<ChonkyNumber> to_sum;
	int carry = 0;

	for (int i = num1.DigitsSize() - 1; i >= 0; i--)
	{
		int curr = num1.m_Number.at(i) - 48;
		if (curr == 0)
			continue;

		std::string curr_line;
		curr_line.insert(curr_line.begin(), (num1.DigitsSize() - 1) - i, '0');

		for (int j = num2.DigitsSize() - 1; j >= 0; j--)
		{
			int multiplyWith = num2.m_Number.at(j) - 48;
			int tot = (curr * multiplyWith) + carry;
			carry = tot / 10;

			curr_line.insert(curr_line.begin(), (tot - (carry * 10)) + 48);
		}

		if (carry)
		{
			curr_line.insert(curr_line.begin(), carry + 48);
			carry = 0;
		}

		to_sum.push_back(ChonkyNumber(curr_line));
	}

	ChonkyNumber::AddAll(to_sum, output);
	output->m_IsNegative = (num1.m_IsNegative && !num2.m_IsNegative) || (!num1.m_IsNegative && num2.m_IsNegative);
}

void ChonkyNumber::Divide(ChonkyNumber& num1, ChonkyNumber& num2, ChonkyNumber* output)
{
	RETURN_IF_NAN_OPERANDS(num1, num2, output);

	if (num2.m_Number == "0")
	{
		output->SetAsIrregular();
#ifdef DEBUG_IRREGULAR_OPERATIONS
		std::cout << "ChonkyNumber illegal division by 0!" << std::endl;
#endif
		return;
	}

	if (num1.m_Number == "0")
	{
		output->ChangeValue(0);
		return;
	}

	if (num1.m_Number == "1")
	{
		output->ChangeValue(num1.m_Number);
		return;
	}

	if (num1.m_IsNegative && !num2.m_IsNegative)
	{
		output->m_IsNegative = true;
		ChonkyNumber::Divide(num1.Negate(), num2, output);
		num1.Negate();
		return;
	}
	else if (!num1.m_IsNegative && num2.m_IsNegative) {
		output->m_IsNegative = true;
		ChonkyNumber::Divide(num1, num2.Negate(), output);
		num2.Negate();
		return;
	}

	int res = 0;
	ChonkyNumber curr = num1;
	while (curr >= num2)
	{
		curr -= num2;
		res++;
	}

	output->ChangeValue(res);
}

void ChonkyNumber::Pow(ChonkyNumber& num, int exp, ChonkyNumber* output)
{
	RETURN_IF_NAN_OPERAND(num, output);

	if (num == "0")
	{
		if (exp == 0)
		{
			output->SetAsIrregular();
#ifdef DEBUG_IRREGULAR_OPERATIONS
			std::cout << "ChonkyNumber illegal number 0 exp to 0" << std::endl;
			return;
#endif
		}
		else {
			output->ChangeValue(0);
			return;
		}
	}

	if (exp == 0)
	{
		output->ChangeValue(1);
		return;
	} 
	else if (exp < 0)
	{
		output->ChangeValue(0);
		return;
	}

	output->ChangeValue(num.m_Number);
	output->m_IsNegative = num.m_IsNegative;

	for (int i = 0; i < exp - 1; ++i)
	{
		ChonkyNumber::Multiply(*output, num, output);
	}
}

void ChonkyNumber::Module(ChonkyNumber& num, int mod, ChonkyNumber* output)
{
	RETURN_IF_NAN_OPERAND(num, output);

	output->m_IsNegative = num.m_IsNegative;

	if (mod == 0)
	{
		output->ChangeValue(0);
		return;
	}

	if (mod == 2)
	{
		output->ChangeValue((num.m_Number[num.m_Number.size() - 1] - 48) % 2);
		return;
	}

	if (mod == 3)
	{
		int sum = 0;
		for (int i = 0; i < num.DigitsSize(); ++i)
		{
			sum += (num.m_Number[i] - 48);
		}
		output->ChangeValue(sum % 3);
		return;
	}

	if (mod == 5)
	{
		output->ChangeValue((num.m_Number[num.m_Number.size() - 1] - 48) % 5);
		return;
	}

	ChonkyNumber curr = num;
	curr.m_IsNegative = false;
	while (curr >= mod)
	{
		curr -= mod;
	}

	output->ChangeValue(curr.m_Number, false);
}

bool ChonkyNumber::IsNumber(std::string& str)
{
	if (str.size() == 0)
		return true;

	bool res = (str[0] == '-') || (str[0] >= '0' && str[0] <= '9');
	unsigned char i = 1;
	while (i < str.size() && res)
	{
		if (str[i] < '0' || str[i] > '9')
			res = false;

		++i;
	}

	return res;
}
