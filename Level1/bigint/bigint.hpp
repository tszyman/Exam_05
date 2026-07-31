#pragma once

#include <iostream>
#include <algorithm>

class bigint {
	public:
		bigint(unsigned int nbr = 0) : _big(std::to_string(nbr)) {};
		bigint(const bigint &b) : _big(b._big) {};

		std::string getBig() const;

		//Additions
		bigint operator+(const bigint &b) const;
		bigint &operator+=(const bigint &b);

		//Increments
		bigint operator++(int);
		bigint &operator++();
		//Shifts
		bigint operator<<(unsigned int n) const;
		bigint &operator<<=(unsigned int n);
		bigint &operator>>=(const bigint &b);

		//Comparisons
		bool operator<(const bigint &b) const;
		bool operator>(const bigint &b) const;
		bool operator<=(const bigint &b) const;
		bool operator>=(const bigint &b) const;
		bool operator==(const bigint &b) const;
		bool operator!=(const bigint &b) const;

	private:
		std::string _big;

};

std::ostream &operator<<(std::ostream &out, const bigint &b);