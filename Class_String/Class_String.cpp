#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-------------------------------\n";

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

	//				Constructors:

	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "DeflaConstruct:\t" << this << endl;
	}
	String(const char* str) :size(strlen(str) + 1), str(new char[size] {})
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other) :size(other.size), str(new char[size] {})
	{
		//this->size = other.size;
		//this->str = new char[size]{};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other) :size(other.size), str(other.str)
	{
		//					MoveConstructor выполняет ShellowCopy (поверхностное копирование)
		//this->size = other.size;
		//this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "destructor:\t" << this << endl;
	}

	//				Operators:

	String& operator=(const String& other)
	{
		/*int a = 2;
		int b = 3;
		a = b;*/
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
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}

	//				Methods:

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRACTORS_CHEC
#define MOV_METHODS_CHEC

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

#ifdef MOV_METHODS_CHEC
	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = ("World");
	cout << str2 << endl;
	//String str3 = str1 + " " + str2; //MoveConstructor
	String str3;
	str3 = str1 + str2;
	//str3.print();
	cout << str3 << endl;
#endif // MOV_METHODS_CHEC

}