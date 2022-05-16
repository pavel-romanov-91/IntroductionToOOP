#include<iostream>
using namespace std;

#define delimiter "\n--------------------------------\n"

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
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Singleargumentconstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "constructor:\t" << this << endl;
	}
	//Class(const Class& other);
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
		//			Operators:
	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//			Methods
	double distance(const Point& other)
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

double distance(const Point& A, const Point& B);

//#define STRUCT_POINT
//#define DISTANC
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK_1
#define ASSIGNMENT_CHECK_2

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
	cout << delimiter << endl;
	cout << "Растояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Растояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Растояние между точки А и В:	  " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Растояние между точки B и A:	  " << B.distance(A) << endl;
#endif // DISTANC

#ifdef CONSTRUCTORS_CHECK
	int a(2);
	cout << a << endl;

	Point A;
	A.print();

	Point B = 5;
	B.print();

	Point C(8);
	C.print();

	Point D(2, 3);
	D.print();

	Point E = D;
	E.print();

	Point F(D);
	F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK_1
	Point A(2, 3);
	Point B = A; //CopyConstructor потому что создается объект
	Point C;
	C = B;
#endif // ASSIGNMENT_CHECK_1

	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
}

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}