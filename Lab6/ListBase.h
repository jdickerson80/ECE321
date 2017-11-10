#ifndef LISTBASE_H
#define LISTBASE_H

#include <cstddef>

namespace Containters {

template< typename dataType, typename nodeType >
class ListBase
{
public:

	typedef ListBase< dataType, nodeType > ThisType;

private:

	nodeType* _first;
	nodeType* _last;

public:

	ListBase()
		: _first( NULL )
		, _last( NULL ) {}

	virtual void insert( dataType data ) = 0;

	virtual void print() = 0;

	virtual void printSorted() = 0;

	virtual void printReverse() = 0;

	nodeType* first()
	{
		return _first;
	}

	void setFirst( nodeType* newNode )
	{
		_first = newNode;
	}

	nodeType* last()
	{
		return _last;
	}

	void setLast( nodeType* newNode )
	{
		_last = newNode;
	}

};
} // namespace Containters

#endif
