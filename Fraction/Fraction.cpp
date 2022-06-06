#include"Fraction.h"

#define CONSTRUCTOR_CHEC
//#define HOM_VORK_FRACTIN
//#define ARITHMETICAL_OPERATORS_CHEC
//#define INCRIMENT_CHECK
//#define HOM_WORK
//#define COVERSIONS_FROM_OTHER_TO_CLASS
//#define COVERSIONS_FROM_OTHER_TO_CLASS_TO_OTHER


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
	cout << (double)A << endl;

	/*A.set_integer(123);
	A.set_numerator(55);
	A.set_denominator(77);*/
	A(123, 55, 77);
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

#ifdef COVERSIONS_FROM_OTHER_TO_CLASS_TO_OTHER
/*Fraction A = Fraction(2, 3, 4);
int a = (int) A;
cout << a << endl;
double b = A;
cout << b << endl;
cout << delimiter;*/
//Проверочный код должен заработать :
	Fraction A = 2.75;
	cout << A << endl;
#endif // COVERSIONS_FROM_OTHER_TO_CLASS_TO_OTHER

	

}