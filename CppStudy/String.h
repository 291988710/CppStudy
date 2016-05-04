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
	//һ�����صĹ��캯�����ṩ�Զ���ʼ������
	String();
	String( const char* );
	String( const String& );

	//�����������Զ�����
	~String();

	//һ�����صĸ�ֵ������
	String& operator=( const String& );
	String& operator=( const char* );

	//һ�����صĵ��ڲ�����
	bool operator==( const String& );
	bool operator==( const char* );

	//���ص��±������
	char& operator[](int );

	//��Ա���ʺ���
	int size() { return _size; }
	char* c_str() { return _string; } 

private:
	int _size;
	char *_string;
};