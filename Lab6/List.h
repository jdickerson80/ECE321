#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <Node.h>
#include <ListBase.h>

namespace Containters {

template< typename dataType >
class DLList : public ListBase< dataType, Nodes::DLLNode< dataType > >
{
public:

	typedef Nodes::DLLNode< dataType > NodeType;
	typedef DLList< dataType > ThisType;
	typedef void (*SortingFunction)( ThisType* );

private:

	typedef ListBase< dataType, NodeType > BaseType;

public:

	DLList()
		: BaseType() {}

	void insert( dataType data )
	{
		NodeType* newNode = new NodeType( data );

		if ( BaseType::last() == NULL )
		{
			BaseType::setFirst( newNode );
			BaseType::setLast( newNode );
		}
		else
		{
			BaseType::last()->setNext( newNode );
			newNode->setPrevious( BaseType::last() );
			newNode->setNext( BaseType::first() );
			BaseType::first()->setPrevious( newNode );
			BaseType::setLast( newNode );
		}
	}

	void print()
	{
		NodeType* node = BaseType::first();

		if ( node == NULL )
		{
			printf( "The list is EMPTY!!!!\r\n" );
		}
		else
		{
			printf( "The contents of the list are: " );

			do
			{
				printf("%d, ", node->data() );
				node = node->next();
			} while ( node != BaseType::first() );

			printf("\r\n");
		}
	}

	void printReverse()
	{
		NodeType* node = BaseType::last();

		if ( node == NULL )
		{
			printf( "The list is EMPTY!!!!\r\n" );
		}
		else
		{
			printf( "The contents of the list are: " );

			do
			{
				printf("%d, ", node->data() );
				node = node->previous();
			} while ( node != BaseType::last() );

			printf("\r\n");
		}
	}

	void sortList( SortingFunction sortingFunction )
	{
		if ( BaseType::first() == BaseType::last() )
		{
			printf( "Sorting empty list!!!!\r\n" );
			return;
		}

		sortingFunction( this );
	}

};
} // namespace Containters

#endif
