#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <Node.h>
#include <ListBase.h>

namespace Containters {

template< typename dataType >
class SLLList : public ListBase< dataType, Nodes::SLLNode< dataType > >
{
public:

	typedef Nodes::SLLNode< dataType > NodeType;

private:

	typedef ListBase< dataType, NodeType > BaseType;

public:

	SLLList()
		: BaseType() {}

	void insert( dataType data )
	{
		NodeType* newNode = new NodeType( data );

		if ( BaseType::last() == NULL )
		{
			BaseType::setFirst( newNode );
		}
		else
		{
			BaseType::last()->setNext( newNode );
		}

		BaseType::setLast( newNode );
	}

	void print()
	{
		typename NodeType::NodeBaseType* node = BaseType::first();

		if ( node == NULL )
		{
			printf( "The list is EMPTY!!!!\r\n" );
		}
		else
		{
			printf( "The contents of the list are: " );
			for ( ; node != NULL; node = node->next() )
			{
				printf("%d, ", node->data() );
			}
			printf("\r\n");
		}
	}

	void printSorted()
	{

	}

	void printReverse()
	{

	}

};
} // namespace Containters

#endif
