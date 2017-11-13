#include <iostream>
#include <time.h>
#include <cstdlib>
#include "../Lab6/List.h"

#define ListSize ( 100 )

using namespace std;

typedef Containters::DLList< int > IntList;

void bubbleSort( IntList* list );

int main()
{
	srand( time( NULL ) );
	typedef Containters::DLList< int > IntList;
	IntList myList;

	int looper = 0;
	myList.print();


	for ( ; looper < ListSize; ++looper )
	{
		myList.insert( rand() % 100 );
	}

	myList.print();

	myList.sortList( &bubbleSort );

	myList.print();

	return 0;
}

void bubbleSort( IntList* list )
{
	IntList::NodeType* first = list->first();
	IntList::NodeType* last = list->last();
	bool didSort = false;

	do
	{
		for ( last = list->last(); last > first; last = last->previous() )
		{
			if ( last->previous()->data() > last->data() )
			{
				didSort = true;
				int temp = last->previous()->data();
				last->previous()->data() = last->data();
				last->data() = temp;
			}
		}

		if ( !didSort )
		{
			printf("already sorted\r\n");
			return;
		}

		first = first->next();

	} while ( first != list->last()->next() );
}
