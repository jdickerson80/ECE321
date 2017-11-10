#include <iostream>
#include <List.h>

using namespace std;

int main()
{
	Containters::DLList< int > myList;

	myList.print();
	int looper = 0;

	for ( ; looper < 100; ++looper )
	{
		myList.insert( looper );
	}

	myList.print();
	myList.printReverse();
	return 0;
}
