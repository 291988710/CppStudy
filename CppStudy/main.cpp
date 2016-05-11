/************************************************************************
* CopyRight: LLC All Rights Reserved
* Title: main.cpp
* author: LLC
* date: 2016/4/20
* version: V1.0
************************************************************************/

/************************************************************************
 * include file
************************************************************************/
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
using namespace std;

/************************************************************************
 * global variable declaration
************************************************************************/
typedef vector<string> textWords;
typedef vector<string>::difference_type diffType;

/************************************************************************
 * pre declaration
************************************************************************/

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
 * class declaration
************************************************************************/
class GreaterThan
{
public:
	GreaterThan(int sz = 6) : _size(sz) {};
	int size() {return _size;}
	bool operator() (const string &s1) {return s1.size() > _size;}
private:
	int _size;
};

class PrintElem
{
public:
	PrintElem(int lineLen = 8) : _line_length(lineLen), _cnt(0) {};
	void operator() (const string &elem)
	{
		++_cnt;
		if (_cnt % _line_length == 0)
		{
			cout<<'\n';
		}
		cout<<elem<<" ";
	}
private:
	int _line_length;
	int _cnt;
};

class LessThan
{
public:
	bool operator() (const string &s1, const string &s2)
	{
		return s1.size() < s2.size();
	}
};

/************************************************************************
* Title: ProcessVocab
* Description: 处理字符串函数
* Param: Vector<textWords> *pVec
* Return: void
************************************************************************/
void ProcessVocab(vector<textWords> *pVec)
{
	if (!pVec)
	{
		cout<<"pVec is not valuable."<<endl;
		return;
	}
	vector<string> texts;
	vector<textWords>::iterator iter;

	for (iter = pVec->begin(); iter != pVec->end(); ++iter)
	{
		copy((*iter).begin(), (*iter).end(), back_inserter(texts));
	}

	//sort texts' elements
	sort(texts.begin(), texts.end());

	//output texts message
	for_each(texts.begin(), texts.end(), PrintElem());
	cout<<"\n\n";

	//delete repeated elements
	vector<string>::iterator it;
	it = unique(texts.begin(), texts.end());
	texts.erase(it, texts.end());

	//output texts message
	for_each(texts.begin(), texts.end(), PrintElem());
	cout<<"\n\n";

	//sort elements by default length 6
	//stable_sort() save the sequence of the same elements
	stable_sort(texts.begin(), texts.end(), LessThan());
	cout<<"\n\n";

	//count the number of elements that greater than 6
	int cnt = 0;

	cnt = count_if(texts.begin(), texts.end(), GreaterThan());
	cout<<"Number of words greater than length six are: "<<cnt<<endl;

	static string rw[] = {"and", "if", "or", "but", "the"};
	vector<string> remove_words(rw, rw+5);
	vector<string>::iterator it2 = remove_words.begin();

	for (; it2 != remove_words.end(); ++it2)
	{
		int cnt = 0;

		cnt = count(texts.begin(), texts.end(), *it2);
		cout<<cnt<<" instances removed: "<<(*it2)<<endl;
		texts.erase(remove(texts.begin(), texts.end(), *it2), texts.end());
	}

	cout<<"\n\n";
	for_each(texts.begin(), texts.end(), PrintElem());
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
	struct stA
	{
		int nA;
		double dB;
	};
	stA stA1;

	int nMinA = TemplateTest(arrayA);
	cout<<"nMinA: "<<nMinA<<endl;
	double dMinB = TemplateTest(arrayB);
	cout<<"dMinB: "<<dMinB<<endl;
	cout<<typeid(dMinB).name()<<"\t"<<typeid(stA1).name()<<endl;

	vector<textWords> sample;
	vector<string> t1, t2;
	string t1fn("1.txt"), t2fn("2.txt");
		
	//input file name
	//cout<<"text file #1: ";
	//cin>>t1fn;
	//cout<<"text file #2: ";
	//cin>>t2fn;

	//open the file
	ifstream infile1(t1fn.c_str());
	ifstream infile2(t2fn.c_str());

	istream_iterator<string> inputSet1(infile1), eos;
	istream_iterator<string> inputSet2(infile2);

	copy(inputSet1, eos, back_inserter(t1));	//back_inserter Creates an iterator that can insert elements at the back of a specified container. It is similar to push_back
	copy(inputSet2, eos, back_inserter(t2));

	sample.push_back(t1);
	sample.push_back(t2);
	ProcessVocab(&sample);

	return 0;
}