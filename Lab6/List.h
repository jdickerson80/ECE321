#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include "Node.h"
#include "ListBase.h"

namespace Containers {

template< typename DataType >
class DLList : public ListBase< DataType, Nodes::DLLNode< DataType > >
{
public:

    typedef Nodes::DLLNode< DataType > NodeType;
    typedef DLList< DataType > ThisType;
    typedef void (*SortingFunction)( ThisType* );

private:

    typedef ListBase< DataType, NodeType > BaseType;

public:

    DLList()
        : BaseType() {}

    void insert( DataType data )
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
			printf( "The contents of the list in reverse are: " );

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
        if ( BaseType::first() == NULL || BaseType::last() == NULL )
        {
            printf( "Sorting empty list!!!!\r\n" );
            return;
        }

        sortingFunction( this );
    }

};

template< typename DataType >
class SparseArray : public ListBase< DataType, Nodes::SparseArrayNode< DataType > >
{
private:
    typedef Nodes::SparseArrayNode< DataType > NodeType;
    typedef ListBase< DataType, NodeType > BaseType;

    void printReverse()
    {

    }

    void insert( DataType data )
    {

    }

    void insert( DataType data
                 , unsigned int x
                 , unsigned int y )
    {
        NodeType* newNode = new NodeType( data, x, y );
        BaseType::last()->setNext( newNode );
        BaseType::setLast( newNode );
    }

public:

    SparseArray()
        : ListBase< DataType, Nodes::SparseArrayNode< DataType > >()
    {

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
            printf( "The contents of the list are:\r\n" );

            do
            {
                printf("x: %d y: %d data: %d\r\n", node->x(), node->y(), node->data() );
                node = node->next();
            } while ( node != BaseType::last() );

            printf("\r\n");
        }
    }

    template< int xDimension, int yDimension >
    void fillSparseArray( DataType array[ xDimension ][ yDimension ] )
    {
        NodeType* firstNode = new NodeType( 0, xDimension, yDimension );
        BaseType::setFirst( firstNode );
        BaseType::setLast( firstNode );

        size_t x = 0;
        size_t y = 0;

        DataType tempData = 0;

        for ( ; x < xDimension; x++ )
        {
            for ( y = 0; y < yDimension; y++ )
            {
                tempData = array[ x ][ y ];
                if ( tempData != 0 )
                {
                    insert( tempData, x, y );
                }
            }
        }
    }
};

} // namespace Containters

#endif
