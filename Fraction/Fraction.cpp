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
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1argConstructor:" << this << endl;
	}
	explicit Fraction(double decimal)
	{
		decimal += 1e-11;
		integer = decimal;
		denominator = 1e+9;
		decimal -= integer;
		numerator = decimal * denominator;
		translation();
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
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

	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	//			Type-cast operators
	explicit operator int()const
	{
		return integer;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
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

	Fraction& division()const
	{
		Fraction division = *this;
		division.to_improper();
		int buffer = division.numerator;
		division.numerator = division.denominator;
		division.denominator = buffer;
		return division;
	}

	Fraction& translation()
	{
		if (numerator == 0)return *this;
		int more, les;
		int rest;
		if (numerator > denominator)
		{
			more = numerator;
			les = denominator;
		}
		else
		{
			les = numerator;
			more = denominator;
		}
		do
		{
			rest = more % les;
			more = les;
			les = rest;
		} while (rest);
		int DIV = more;
		numerator /= DIV;
		denominator /= DIV;
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
	ostream& print(ostream& os)const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer)os << "(";
			os << numerator << "/" << denominator;
			if (integer)os << ")";
		}
		if (integer == 0 && numerator == 0)os << 0;
		return os;
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
	return left.get_numerator() == right.get_numerator() &&	left.get_denominator() == right.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);

}
bool operator>(Fraction left, Fraction right)
{
	return	left.to_improper().get_numerator() * right.get_denominator() > right.to_improper().get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{

	return	left.to_improper().get_numerator() * right.get_denominator() < 	right.to_improper().get_numerator() * left.get_denominator();
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

ostream& operator << (ostream& os, const Fraction& obj)
{
	/*if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	return os;*/
	return obj.print(os);
}

istream& operator>>(istream& is, Fraction& obj)
{
	/*int integer;
	int numerator;
	int denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);*/

	const int SIZE = 256;
	char bufer[SIZE] = {};
	char delimiters[] = "() /";
	is.getline(bufer, SIZE);
	char* number[3] = {};
	int i = 0;
	for (char* pch = strtok(bufer, delimiters); pch; pch = strtok(NULL, delimiters))
	{
		number[i++] = pch;
	}
	
	char* pch = strtok(bufer, delimiters);
	while (pch)
	{
		number[i++] = pch;
		pch = strtok(NULL, delimiters);
	}

	switch (i)
	{
	case 1: obj.set_integer(atoi(number[0])); break;
	
	case 2:
		obj.set_numerator(atoi(number[0]));
		obj.set_denominator(atoi(number[1]));
		break;
	case 3:
		obj.set_integer(atoi(number[0]));
		obj.set_numerator(atoi(number[1]));
		obj.set_denominator(atoi(number[2]));
	}


	return is;

}

//#define CONSTRUCTOR_CHEC
//#define HOM_VORK_FRACTIN
//#define ARITHMETICAL_OPERATORS_CHEC
//#define INCRIMENT_CHECK
//#define HOM_WORK
//#define COVERSIONS_FROM_OTHER_TO_CLASS


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

#ifdef ARITHMETICAL_OPERATORS_CHEC
	Fraction A(2, 3, 4);
	Fraction B(19, 5);
	/*A.print();
	B.print();

	int a = 2;
	int b = 3;
	int c = a * b;

	Fraction C = A * B;
	C.print();
	(A / B).print();
	(A + B).print();*/

	A *= B;
	A.print();


#ifdef HOM_VORK_FRACTIN
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
#endif // HOM_VORK_FRACTIN
#endif // ARITHMETICAL_OPERATORS_CHEC

#ifdef INCRIMENT_CHECK
	for (Fraction i(1, 2); i.get_integer() < 10; ++i)
	{
		i.print();
	}
#endif // INCRIMENT_CHECK

#ifdef HOM_WORK
	//cout << (Fraction(1, 1, 2) != Fraction(5, 10)) << endl;

/*Fraction A(1, 2);
cout << A << endl;
A.print();*/

//Проверочный код должен заработать :
	Fraction A;
	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;
	/*Варианты ввода :
		1 / 2
		5
		2(3 / 4)
		2 3 / 4*/
#endif // HOM_WORK

#ifdef COVERSIONS_FROM_OTHER_TO_CLASS
		/*Fraction A = 5;
cout << A << endl;*/
	Fraction B;
	cout << delimiter;
	B = Fraction(8);
	cout << delimiter;
	cout << B << endl;
#endif // COVERSIONS_FROM_OTHER_TO_CLASS

	Fraction A = Fraction(2, 3, 4);
	int a = (int) A;
	cout << a << endl;
	double b = A;
	cout << b << endl;
	cout << delimiter;
	//Проверочный код должен заработать :
	Fraction A = 2.75;
	cout << A << endl;
}