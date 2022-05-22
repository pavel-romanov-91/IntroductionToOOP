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

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefolConstructors:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}


	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor: \t" << this << endl;
	}

	//			Operators

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssigment:\t" << this << endl;
		return *this;
	}
	~Fraction()
	{
		cout << "Destructor\t" << this << endl;
	}

	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}


	//			Method


	Fraction& to_proper()
	{
		//Выделяет из неправильной дроби целую часть
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		//Целую часть интергрирует в числитель
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction& division()
	{
		to_improper();
		int buffer = numerator;
		numerator = denominator;
		denominator = buffer;
		return *this;
	}


	void print()const
	{
		if (integer) cout << integer;
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

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	result.to_proper();
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
}

Fraction operator/(Fraction left, Fraction right)
{
	return left * right.division();
}

Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return Fraction
	(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

bool operator==(Fraction left, Fraction right)
{
	return left.get_numerator() == right.get_numerator() &&
		left.get_denominator() == right.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);

}
bool operator>(Fraction left, Fraction right)
{
	return	left.to_improper().get_numerator() * right.get_denominator() >
		right.to_improper().get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{

	return	left.to_improper().get_numerator() * right.get_denominator() <
		right.to_improper().get_numerator() * left.get_denominator();
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

//#define CONSTRUCTOR_CHEC

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHEC
	Fraction A;
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = C;
	E.print();

	A = D;
	A.print();
#endif // CONSTRUCTOR_CHEC

	Fraction A(2, 3, 4);
	Fraction B(19, 5);
	A.print();
	B.print();

	int a = 2;
	int b = 3;
	int c = a * b;

	Fraction C = A * B;
	C.print();

	cout << delimiter << endl;
	(A / B).print();
	(A + B).print();
	(A - B).print();
	cout << delimiter << endl;
	A *= B;
	A.print();
	A /= B;
	A.print();
	A += B;
	A.print();
	A -= B;
	A.print();
	cout << delimiter << endl;
	cout << (A == B) << endl;
	cout << (A != B) << endl;
	cout << (A > B) << endl;
	cout << (A < B) << endl;
	cout << (A >= B) << endl;
	cout << (A <= B) << endl;
}