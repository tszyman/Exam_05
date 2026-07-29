#pragma once
#include <iostream>
class vect2 {
	public:
	//constructors(5)
		vect2() : x(0), y(0) {};					//default
		vect2(int x, int y) : x(x), y(y) {};		//param
		vect2(const vect2 &v) : x(v.x), y(v.y) {};	//copy
		vect2 &operator=(const vect2 &v)			//ass
		{
			if (this != &v)
			{
				x = v.x;
				y = v.y;
			}
			return (*this);
		}
		~vect2() {};//dest
	//access(2 int)
	int operator[](int i) const
	{
		return(i == 0 ? x : y);
	}
	int &operator[](int i)
	{
		return(i == 0 ? x : y);
	}
	//increment(4)
	vect2 operator++(int)
	{
		vect2 cp(*this);
		++x;
		++y;
		return(cp);
	}
	vect2 &operator++()
	{
		++x;
		++y;
		return(*this);
	}
	vect2 operator--(int)
	{
		vect2 cp(*this);
		--x;
		--y;
		return(cp);
	}
	vect2 &operator--()
	{
		--x;
		--y;
		return(*this);
	}
	//math(6)
	vect2 operator+(const vect2 &v) const
	{
		vect2 cp(*this);
		cp.x += v.x;
		cp.y += v.y;
		return(cp);
	}
	vect2 &operator+=(const vect2 &v)
	{
		x += v.x;
		y += v.y;
		return(*this);
	}
	vect2 operator-(const vect2 &v) const
	{
		vect2 cp(*this);
		cp.x -= v.x;
		cp.y -= v.y;
		return(cp);
	}
	vect2 &operator-=(const vect2 &v)
	{
		x -= v.x;
		y -= v.y;
		return(*this);
	}
	vect2 operator*(int n) const
	{
		vect2 cp(*this);
		cp.x *= n;
		cp.y *= n;
		return(cp);
	}
	vect2 &operator*=(int n)
	{
		x *= n;
		y *= n;
		return(*this);
	}
	//unary minus(1)
	vect2 operator-() const
	{
		vect2 cp(*this);
		cp.x = -cp.x;
		cp.y = -cp.y;
		return(cp);
	}
	//bool(2 bool)
	bool operator==(const vect2 &v) const
	{
		return(x == v.x && y == v.x);
	}
	bool operator!=(const vect2 &v) const
	{
		return(x != v.x || y != v.y);
	}
	//additional(2 friend)
	friend std::ostream &operator<<(std::ostream &out, const vect2 &v)
	{
		out << "{" << v.x << ", " << v.y << "}";
		return(out);
	}
	friend vect2 operator*(int n, const vect2 &v)
	{
		vect2 cp(v);
		cp *= n;
		return(cp);
	}

	private:
		int x,y;
};