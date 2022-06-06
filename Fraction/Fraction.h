#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


#define delimiter "\n--------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);
Fraction operator+(Fraction left, Fraction right);
Fraction operator-(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	//				Constructors

	Fraction();
	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);

	Fraction(int integer, int numerator, int denominator);

	//			Operators

	Fraction& operator=(const Fraction& other);
	~Fraction();

	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator+=(const Fraction& other);
	Fraction& operator-=(const Fraction& other);

	Fraction& operator++();
	Fraction operator++(int);

	Fraction& operator()(int integer, int numerator, int denominator);

	//			Type-cast operators
	explicit operator int()const;
	operator double()const;

	//			Method

	Fraction& to_proper();
	Fraction& to_improper();

	Fraction& division()const;
	Fraction& translation();
	void print()const;
	ostream& print(ostream& os)const;
};

