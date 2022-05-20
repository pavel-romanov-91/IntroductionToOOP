#include<iostream>
using namespace std;

class Fraction
{
	int integer;	//целая часть
	int numerator;	//числитель
	int denominator;	//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	//				Constructors

	/*Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "удолениеConstructors:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Constructor 1 параметыр:" << this << endl;
	}
	Fraction(int numera)*/

	Fraction(int integer = 0, int numerator = 0, int denominator = 1)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor: \t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor\t" << this << endl;
	}
	//			Method

	void print()
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

void main()
{
	Fraction A;
	A.print();
	Fraction B = 3;
	B.print();
	Fraction C(1, 2);
	C.print();
}