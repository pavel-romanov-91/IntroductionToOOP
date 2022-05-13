﻿#include<iostream>
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
	double distance(Point dot)
	{
		double x_distance = dot.x - this->x;
		double y_distance = dot.y - this->y;
		double distance = (x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};

double distance(Point A, Point B);

//#define STRUCT_POINT

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
	cout << "Растояние между точки А и В: " << A.distance(B) << endl;
	
}

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = (x_distance * x_distance + y_distance * y_distance);
	return distance;
}