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
* Description: ���Ժ���
* Param: void
* Return: void
************************************************************************/
void Test1()
{
	using npC::print;	//�ڿ���ʹ��using������������ص�������������غ���
	print("Test1");
	//print(4);	//��ʱ�ͻ������Ϊȫ�ֵ�print�������غ����ѱ�����	
}

/************************************************************************
* Title: Test2
* Description: ���Ժ���
* Param: void
* Return: void
************************************************************************/
void Test2()
{
	using namespace npC;	//�ڿ���ʹ��usingָʾ����ʹ���ֿռ��Ա�ɼ��ͺ��������������ֿռ�֮�� �ڶ������ֿռ��λ���ϱ�������һ��
	print("Test2");
	print(4);	//��ʱ����������
}

/************************************************************************
* Title: main
* Description: �������
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

	return 0;
}