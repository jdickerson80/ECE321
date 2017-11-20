#ifndef LISTBASE_H
#define LISTBASE_H

#include <cstddef>
#include <vector>

namespace Containters {

template< typename DataType, typename NodeType >
class ListBase
{
public:

	typedef ListBase< DataType, NodeType > ThisType;

private:

	NodeType* _first;
	NodeType* _last;

public:

	ListBase()
		: _first( NULL )
		, _last( NULL ) {}


	~ListBase()
	{
		if ( _last == NULL )
		{
			return;
		}

		_first->setPrevious( NULL );

		NodeType* node = NULL;

		for ( node = last(); node->previous() != NULL; node = node->previous() )
		{
			delete node;
		}

		delete node;
	}

	virtual void insert( DataType data ) = 0;

	virtual void print() = 0;

	virtual void printReverse() = 0;

	NodeType* first()
	{
		return _first;
	}

	void setFirst( NodeType* newNode )
	{
		_first = newNode;
	}

	NodeType* last()
	{
		return _last;
	}

	void setLast( NodeType* newNode )
	{
		_last = newNode;
	}
};


} // namespace Containters

#endif
