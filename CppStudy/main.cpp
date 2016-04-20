//main.cpp
/************************************************************************/
/*                       
	Created time: 2016/4/20
	Created author: llc
	Function: C++ primer study
*/
/************************************************************************/

#include <iostream>

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
	
	return 0;
}