#ifndef NODE_H
#define NODE_H

#include <cstddef>

namespace Containters {
namespace Nodes {

template < typename dataType >
class NodeBase
{
public:

	typedef NodeBase< dataType > NodeBaseType;

private:

	dataType _data;
	NodeBaseType* _next;

public:

	NodeBase()
		: _data( NULL )
		, _next( NULL ) {}


	NodeBase( dataType data, NodeBaseType* next = NULL )
		: _data( data )
		, _next( next ) {}

	dataType& data()
	{
		return _data;
	}

	NodeBaseType* next()
	{
		return _next;
	}

	void setNext( NodeBaseType* newNode )
	{
		_next = newNode;
	}
};


template< typename dataType >
class SLLNode : public NodeBase< dataType >
{
public:

	typedef SLLNode< dataType > SLLNodeType;

public:

	SLLNode( dataType data, SLLNodeType* nextNode = NULL )
		: NodeBase< dataType >( data, nextNode ) {}

	SLLNode()
		: NodeBase< dataType >() {}
};

template< typename dataType >
class DLLNode
{
public:

	typedef DLLNode< dataType > DLLNodeType;

private:

	DLLNodeType* _previous;

public:

	DLLNode( dataType data, DLLNodeType* nextNode = NULL, DLLNodeType* previousNode = NULL )
		: NodeBase< dataType >( data, nextNode )
		, _previous( previousNode ){}

	DLLNode()
		: NodeBase< dataType >() {}


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
