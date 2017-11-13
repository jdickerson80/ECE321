#ifndef LISTBASE_H
#define LISTBASE_H

#include <cstddef>
#include <vector>

namespace Containters {

template< typename dataType, typename nodeType >
class ListBase
{
public:

	typedef ListBase< dataType, nodeType > ThisType;


	typedef nodeType* iterator;
	typedef const nodeType* const const_iterator;

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

	iterator begin()
	{
		return _first;
	}

	const_iterator being() const
	{
		return _first;
	}

	iterator end()
	{
		return _last;
	}

	const_iterator end() const
	{
		return _last;
	}

};

template< typename nodeType >
typename nodeType::const_iterator operator++( const nodeType& node )
{
	typename nodeType::const_iterator temp = node.next();
	return temp;
}

} // namespace Containters

#endif
