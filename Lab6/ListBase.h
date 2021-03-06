#ifndef LISTBASE_H
#define LISTBASE_H

#include <cstddef>
#include <vector>

namespace Containers {

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

        NodeType* node = first();

        for ( node = first(); node != last(); node = node->next() )
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

    bool isEmpty() const
    {
        return _first == NULL || _last == NULL;
    }

    void popFront()
    {
        if ( first() == last() )
        {
            delete first();

            setFirst( NULL );
            setLast( NULL );
        }
        else
        {
            NodeType* node = first()->next();

            delete first();

            setFirst( node );
        }
    }
};


} // namespace Containers

#endif
