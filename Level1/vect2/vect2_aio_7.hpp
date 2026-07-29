#pragma once
#include <iostream>

class vect2 {
	public:
		//constructors(5)
			vect2() : x(0), y(0) {};//default
			vect2(int x, int y) : x(x), y(y) {};//parametrized
			vect2(const vect2 &v) : x(v.x), y(v.y) {};//copy constructor
			vect2 &operator=(const vect2 &v){
				if(this != &v)
				{
					x = v.x;
					y = v.y;
				}
				return(*this);
			} //assignment
			~vect2() {}; //destructor

		//access(2 int)
		int operator[](int i) const{
			return(i == 0 ? x : y);
		}
		int &operator[](int i){
			return(i == 0 ? x : y);
		}

		//increment(4)
		vect2 operator++(int){	//post increment
			vect2 cp(*this);
			++x;
			++y;
			return (cp);
		}
		vect2 &operator++() {	//pre increment
			++x;
			++y;
			return(*this);
		}
		vect2 operator--(int){
			vect2 cp(*this);
			--x;
			--y;
			return(cp);
		}
		vect2 &operator--(){
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
			return (cp);
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
			return(x == v.x && y == v.y);
		}
		bool operator!=(const vect2 &v) const
		{
			return(x != v.x || y != v.y);
		}

		//additions(2 friend)
		friend std::ostream &operator<<(std::ostream &out, vect2 const &v)
		{
			out << "{" << v.x << ", " << v.y << "}";
			return (out);
		}
		friend vect2 operator*(int n, vect2 const &v)
		{
			vect2 cp(v);
			cp*=n;
			return(cp);
		}

	private:
		int x, y;
};