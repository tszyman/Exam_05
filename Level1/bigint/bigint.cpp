#include "bigint.hpp"

std::string bigint::getBig() const
{
	return(_big);
}

//Additions
bigint &bigint::operator+=(const bigint &b)
{
	int car = 0;
	int i = _big.length() -1;
	int j = b._big.length() -1;

	std::string res = "";
	while( i >= 0 || j >= 0 || car)
	{
		int sum = car;
		if (i >= 0) sum += _big[i--] - '0';
		if (j >= 0) sum += b._big[j--] - '0';
		car = sum / 10;
		res += (sum % 10) + '0';
	}
	std::reverse(res.begin(), res.end());
	_big = res;
	return(*this);
}

bigint bigint::operator+(const bigint &b) const
{
	bigint cp(*this);
	cp += b;
	return(cp);
}

//Increments
bigint bigint::operator++(int)
{
	bigint cp(*this);
	*this += 1;
	return(cp);
}

bigint &bigint::operator++()
{
	*this += 1;
	return(*this);
}

//Shifts
bigint &bigint::operator<<=(unsigned int n)
{
	if (_big != "0")
		_big.append(n, '0');
	return(*this);
}

bigint bigint::operator<<(unsigned int n) const
{
	bigint cp(*this);
	cp <<= n;
	return(cp);
}

bigint &bigint::operator>>=(const bigint &b)
{
	unsigned long n = std::stoul(b.getBig());
	if (n >= _big.length())
		_big = "0";
	else
		_big = _big.substr(0, _big.length() - n);
	return(*this);
}

//Comparisons
bool bigint::operator<(const bigint &b) const
{
	return(_big.length() != b._big.length() ? _big.length() < b._big.length() : _big < b._big);
}
bool bigint::operator>(const bigint &b) const
{
	return(b < *this);
}
bool bigint::operator<=(const bigint &b) const
{
	return!(*this > b);
}
bool bigint::operator>=(const bigint &b) const
{
	return!(*this < b);
}
bool bigint::operator==(const bigint &b) const
{
	return(_big == b._big);
}
bool bigint::operator!=(const bigint &b) const
{
	return !(*this == b);
}

//Stream

std::ostream &operator<<(std::ostream &out, const bigint &b)
{
	out << b.getBig();
	return(out);
}
