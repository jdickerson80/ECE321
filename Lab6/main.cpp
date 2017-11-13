#include <iostream>
#include <List.h>

using namespace std;

typedef Containters::DLList< int > IntList;

void bubbleSort( IntList* list );

int main()
{
	int something;
	typedef Containters::DLList< int > IntList;
	IntList myList;

	myList.print();
	int looper = 0;

	for ( ; looper < 100; ++looper )
	{
		myList.insert( looper );
	}

	myList.sortList( &bubbleSort );

	myList.print();
	myList.printReverse();

	scanf("%d", something );
	return 0;
}

void bubbleSort( IntList* list )
{
	IntList::NodeType* first = list->first();
	IntList::NodeType* last = list->last();

	for ( ; first < last; first = first->next() )
	{
		for ( last->previous(); last > first; last = last->previous() )
		{
			if ( last->previous()->data() > last->data() )
			{
				int temp = last->previous()->data();
				last->previous()->data() = last->data();
				last->data() = temp;
			}
		}
	}
}

//	NodeType* node = BaseType::last();
//do
//{
//	printf("%d, ", node->data() );
//	node = node->previous();
//} while ( node != BaseType::last() );
