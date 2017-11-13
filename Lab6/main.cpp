#include <iostream>
#include <List.h>
#include <time.h>
#include <cstdlib>

#define ListSize ( 100 )

using namespace std;

int main()
{
	srand( time( NULL ) );
	typedef Containters::DLList< int > IntList;
	IntList myList;

	int looper = 0;

	for ( ; looper < ListSize; ++looper )
	{
		myList.insert( rand() % 100 );
	}

	myList.print();

	printf("reverse order: \r\n");

	myList.printReverse();

	return 0;
}
