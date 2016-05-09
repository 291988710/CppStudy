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
 * global variable declaration
************************************************************************/
int a;

/************************************************************************
 * namespace declaration
************************************************************************/
namespace npA
{
	void print(int n) { cout<<"npA\t"<<n<<endl; }
}

namespace npB
{
	void print(double d) { cout<<"npB\t"<<d<<endl; }
}

namespace npC
{
	void print(char *c) { cout<<"npC\t"<<c<<endl; }
}

void print(string s)
{
	cout<<"global\t"<<s<<endl;
}

using namespace npA;
using namespace npB;

/************************************************************************
* Title: Test1
* Description: 测试函数
* Param: void
* Return: void
************************************************************************/
void Test1()
{
	using npC::print;	//在块中使用using声明，则会隐藏掉上面的三个重载函数
	print("Test1");
	//print(4);	//这时就会出错，因为全局的print三个重载函数已被隐藏	
}

/************************************************************************
* Title: Test2
* Description: 测试函数
* Param: void
* Return: void
************************************************************************/
void Test2()
{
	using namespace npC;	//在块中使用using指示符，使名字空间成员可见就好像它们是在名字空间之外 在定义名字空间的位置上被声明的一样
	print("Test2");
	print(4);	//这时就是正常的
}

/************************************************************************
* Title: TemplateTest
* Description: 模板测试函数
* Param: void
* Return: void
************************************************************************/
template<typename Type, int nSize>
Type TemplateTest(Type (&array)[nSize])
{
	Type minVal = array[0];
	for (int i = 0; i < nSize; i++)
	{
		if (array[i] < minVal)
		{
			minVal = array[i];
		}
	}

	return minVal;
}

/************************************************************************
* Title: main
* Description: 函数入口
* Param: void
* Return: int
************************************************************************/
int main()
{
	print(1);
	print(2.2);
	print("main");
	Test1();
	Test2();

	//TemplateTest
	int arrayA[] = { 2, 3, 4, 123, 5, 1, 6};
	double arrayB[] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 0.2};

	int nMinA = TemplateTest(arrayA);
	cout<<"nMinA: "<<nMinA<<endl;
	double dMinB = TemplateTest(arrayB);
	cout<<"dMinB: "<<dMinB<<endl;

	return 0;
}