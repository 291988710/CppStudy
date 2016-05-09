/************************************************************************
* CopyRight: LLC All Rights Reserved
* Title: main.cpp
* author: LLC
* date: 2016/4/20
* version: V1.0
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/************************************************************************
 * namespace decleration
************************************************************************/
namespace npA
{
	void print(int n) { cout<<"npA\t"<<n<<endl; }
}

namespace npB
{
	void print(double d) { cout<<"npB\t"<<d<<endl; }
}

void print(string s)
{
	cout<<"global\t"<<s<<endl;
}

using namespace npA;
using namespace npB;

/************************************************************************
* Title: main
* Description: º¯ÊýÈë¿Ú
* Param: void
* Return: int
************************************************************************/
int main()
{
	print(1);
	print(2.2);
	print("this");

	return 0;
}