#include<iostream>
using namespace std;

#define delimiter "\n-----------------------------------\n"
class String;
String operator+(const String& left, const String& right);


class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//				Constructors
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DeflaConstruct:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "destructor:\t" << this << endl;
	}
	//					Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	//					Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};
String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)cat[i + left.get_size() - 1] = right[i];
	return cat;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
istream& operator>>(istream& is, String& obj)
{
	const int SIZE = 256;
	char bufer[SIZE] = {};
	is >> bufer;
	obj = bufer;
	return is;
}

//#define CONSTRACTORS_CHEC

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRACTORS_CHEC
	String str1;
	str1.print();

	String str2(5);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = str3;
	str4.print();

	String str5;
	str5 = str4;
	str5.print();
#endif // CONSTRACTORS_CHEC

	String str1 = "Hello";
	String str2 = ("World");
	String str3 = str1 + " " + str2;
	str3.print();
	cout << delimiter << endl;
	cout << "Введите строку: "; cin >> str1;
	cout << str1 << endl;
	cout << delimiter << endl;
	//Перегрузить оператор +=
	String str1 = "Hello";
	String str2("World");
	str1 += str2;
	cout << str1 << endl;
}