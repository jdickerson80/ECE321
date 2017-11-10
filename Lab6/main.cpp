#include <iostream>
#include <List.h>

using namespace std;

int main()
{
	Containters::SLLList< int > myList;

	myList.print();
	int looper = 0;

	for ( ; looper < 10; ++looper )
	{
		myList.insert( looper);
	}

	myList.print();
	return 0;
}
