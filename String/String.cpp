#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------------------------------\n"

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
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};	
		cout << "SizeConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)noexcept
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;

		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
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
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete this->str;
		this->size = other.size;
		this->str = other.str;

		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
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

	//					Methods

	void print()const
	{
		cout << "Size:" << size << endl;
		cout << "Str:" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)result[i + left.get_size() - 1] = right[i];
	return result;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	const int SIZE = 1024 * 1000;
	char buffer[SIZE] = {};
	is >> buffer;
	obj = buffer;
	return is;
}

std::istream& getline(std::istream& is, String& obj)
{
	const int SIZE = 1024 * 1000;
	char buffer[SIZE] = {};
	is.getline(buffer, SIZE);
	obj = buffer;
	return is;
}

void main()
{
	setlocale(LC_ALL, "");

	String str1;
	str1.print();
	cout << delimiter;
	String str2(8);	
	str2.print();
	cout << delimiter;
	String str3 = "Hello";
	str3.print();
	cout << delimiter;
	String str4 = "World";
	str4.print();
	cout << delimiter;
	String str5 = str3 + str4;
	cout << delimiter;
	cout << str5 << endl;
	cout << delimiter;
	cout << "¬ведите строку: "; cin >> str1;
	cout << str1 << endl;
}