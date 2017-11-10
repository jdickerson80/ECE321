#ifndef NODE_H
#define NODE_H

#include <cstddef>

namespace Containters {
namespace Nodes {

template< typename dataType >
class DLLNode
{
public:

	typedef DLLNode< dataType > DLLNodeType;

private:

	dataType _data;
	DLLNodeType* _next;
	DLLNodeType* _previous;

public:

	DLLNode( dataType data, DLLNodeType* nextNode = NULL, DLLNodeType* previousNode = NULL )
		: _data( data )
		, _next( nextNode )
		, _previous( previousNode ){}

	DLLNode()
		: _data( NULL )
		, _next( NULL )
		, _previous( NULL ){}


	dataType& data()
	{
		return _data;
	}

	DLLNodeType* next()
	{
		return _next;
	}

	void setNext( DLLNodeType* newNode )
	{
		_next = newNode;
	}

	DLLNodeType* previous()
	{
		return _previous;
	}

	void setPrevious( DLLNodeType* newNode )
	{
		_previous = newNode;
	}
};

} // namespace Nodes
} // namespace Containters
#endif
