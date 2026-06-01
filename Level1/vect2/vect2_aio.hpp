#pragma once
#include <iostream>

class vect2
{
	private:
		int x, y;

	public:
		//constructors (4)
		vect2() : x(0), y(0) {};
		vect2(int x, int y) : x(x), y(y) {};
		vect2(const vect2 &v) : x(v.x), y(v.y) {};
		vect2 &operator=(const vect2 &v)
		{
			if (this != &v)
			{
				x = v.x;
				y = v.y;
			}
			return (*this);
		}
		~vect2() {};

		//Access (2)
		int operator[](int i) const
		{
			return (i == 0 ? x : y);
		}

		int &operator[](int i)
		{
			return ( i == 0 ? x : y);
		}

		//Increment (4)
		vect2 &operator++() //pre-increment (++v1)
		{
			++x;
			++y;
			return (*this);
		}
		vect2 operator++(int) //post-increment (v1++)
		{
			vect2 copy(*this);
			++x;
			++y;
			return (copy);
		}
		vect2 &operator--()
		{
			--x;
			--y;
			return(*this);
		}
		vect2 operator--(int)
		{
			vect2 copy(*this);
			--x;
			--y;
			return(copy);
		}

		//Math (6)
		vect2 operator+(const vect2 &v) const
		{
			vect2 cp(*this);
			cp.x += v.x;
			cp.y += v.y;
			return (cp);
		}
		vect2 &operator+=(const vect2 &v)
		{
			x += v.x;
			y += v.y;
			return (*this);
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

		//Unary minus (1)
		vect2 operator-() const
		{
			vect2 cp(*this);
			cp.x = -cp.x;
			cp.y = -cp.y;
			return (cp);
		}
		
		//Bool (2)
		bool operator==(const vect2 &v) const
		{
			return (x == v.x && y == v.y);
		}
		bool operator!=(const vect2 &v) const
		{
			return (x != v.x || y != v.y);
		}

		//Additional (2)
		friend std::ostream &operator<<(std::ostream &out, const vect2 &v)
		{
			out << "{" << v.x << ", "<< v.y << "}";
			return (out);
		}

		friend vect2 operator*(int n, const vect2 &v)
		{
			vect2 cp(v);
			cp *= n;
			return (cp);
		}
};