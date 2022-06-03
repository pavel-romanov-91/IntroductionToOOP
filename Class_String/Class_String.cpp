#include"String.h"


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
	String str4 = str3;
	cout << str4 << endl;
#endif // MOV_METHODS_CHEC
	
}