//main.cpp
/************************************************************************/
/*                       
	Created time: 2016/4/20
	Created author: llc
	Function: C++ primer study
*/
/************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	const char *st = "The next time to go.";
	const char *p = st;
	int iLen = 0;
	while (*p++)
	{
		++iLen;
	}
	cout<<iLen<<"; "<<st<<endl;
	int a[3] = {1,2,3};
	vector<int> vec1(a,a+3);
	vector<int> vec2;
	vector<int>::iterator iter1;
	vector<int>::iterator iter2;
	iter2 = vec2.begin();
	iter1 = iter2;
	if (iter1 == iter2)
	{
	}
	//iter1 = vec1.begin();
	*iter1;
	iter1++;

	return 0;
}