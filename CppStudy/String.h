/************************************************************************
* CopyRight: LLC All Rights Reserved
* Title: String.h
* author: LLC
* date: 2016/4/22
* version: V1.0
************************************************************************/

#include <iostream>

class String;

//istream& operator>>( istream&, String& );
//ostream& operator<<( ostream&, const String& );

class String
{
public:
	//一组重载的构造函数，提供自动初始化功能
	String();
	String( const char* );
	String( const String& );

	//析构函数，自动析构
	~String();

	//一组重载的赋值操作符
	String& operator=( const String& );
	String& operator=( const char* );

	//一组重载的等于操作符
	bool operator==( const String& );
	bool operator==( const char* );

	//重载的下标操作符
	char& operator[](int );

	//成员访问函数
	int size() { return _size; }
	char* c_str() { return _string; } 

private:
	int _size;
	char *_string;
};