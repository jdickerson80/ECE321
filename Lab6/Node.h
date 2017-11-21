#ifndef NODE_H
#define NODE_H

#include <cstddef>

namespace Containers {
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

template< typename DataType >
class SparseArrayNode
{
public:

    typedef SparseArrayNode< DataType > SparseArrayNodeType;

private:

    DataType _data;
    unsigned int _x;
    unsigned int _y;

    SparseArrayNodeType* _next;

public:

    SparseArrayNode( DataType data
                     , unsigned int x
                     , unsigned int y
                     , SparseArrayNodeType* nextNode = NULL )
        : _data( data )
        , _x( x )
        , _y( y )
        , _next( nextNode ) {}

    SparseArrayNode()
        : _data( NULL )
        , _next( NULL ) {}

    DataType& data()
    {
        return _data;
    }

    SparseArrayNodeType* next()
    {
        return _next;
    }

    void setNext( SparseArrayNodeType* newNode )
    {
        _next = newNode;
    }

    unsigned int x() const
    {
        return _x;
    }

    unsigned int y() const
    {
        return _y;
    }
};

} // namespace Nodes
} // namespace Containters
#endif
