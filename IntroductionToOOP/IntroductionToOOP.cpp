#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//			Constructors:
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}


	//			Methods
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << " X = " << x << "\tY = " << y << endl;
	}
};

double distance(Point A, Point B);

//#define STRUCT_POINT
//#define DISTANC

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;
	int a; // обьявление переменной а типа 'int'
	Point A;//обьявления переменной A типа 'Point' 
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	cout << (*pA).x << "\t" << (*pA).y << endl;

	cout << sizeof(Point) << endl;
	cout << typeid(A).name() << endl;
#endif // STRUCT_POINT

#ifdef DISTANC
	Point A;
	double x = 2, y = 3;
	//cout << "Введите координаты точки: "; cin >> x >> y;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << "Растояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "Растояние от точки B до точки A: " << B.distance(A) << endl;
	cout << "Растояние между точки А и В:	  " << A.distance(B) << endl;
	cout << "Растояние между точки B и A:	  " << B.distance(A) << endl;
#endif // DISTANC

	int a;

	Point A;
	A.print();
}

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}