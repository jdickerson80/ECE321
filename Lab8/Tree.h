#ifndef TREE_H
#define TREE_H

#include <cstdlib>
#include <algorithm>
#include <stdio.h>

namespace Containers {
namespace Tree {

template< typename DataType >
struct Node
{
    DataType data;
    Node* left;
    Node* right;

    Node()
        : data( 0 )
        , left( NULL )
        , right( NULL )
    {}

    Node( DataType data, Node* left = NULL, Node* right = NULL )
        : data( data )
        , left( left )
        , right( right )
    {}
};


struct Functions
{
private:

    Functions();

public:
    template< typename Tree >
    static int depth( Tree tree )
    {
        if ( tree == NULL )
        {
            return 0;
        }

        return 1 + std::max( depth( tree->left ), depth( tree->right ) );
    }

    template< typename Tree >
    static int numberOfLeaves( Tree tree )
    {
        if ( tree->left == NULL && tree->right == NULL )
        {
            return 1;
        }

        int leafNumber = 0;

        if ( tree->left )
        {
            leafNumber += numberOfLeaves( tree->left );
        }

        if ( tree->right )
        {
            leafNumber += numberOfLeaves( tree->right );
        }

        return leafNumber;
    }

    template< typename Tree, typename DataType >
    static void balancedTreeInsert( Tree* tree, DataType data )
    {
        if ( *tree == NULL )
        {
            *tree = new Node< DataType >( data );
        }
        else
        {
            int leftSize = depth( (*tree)->left );
            int rightSize = depth( (*tree)->right );

            if ( leftSize <= rightSize )
            {
                balancedTreeInsert( &(*tree)->left, data );
            }
            else
            {
                balancedTreeInsert( &(*tree)->right, data );
            }
        }
    }

    template< typename Tree, typename DataType >
    static void binarySearchTreeInsert( Tree* tree, DataType data )
    {
        if ( *tree == NULL )
        {
            *tree = new Node< DataType >( data );
        }
        else
        {
            if ( data > (*tree)->data )
            {
                binarySearchTreeInsert( &(*tree)->right, data );
            }
            else
            {
                binarySearchTreeInsert( &(*tree)->left, data );
            }
        }
    }

    template< typename Tree >
    static void printDepthTraverse( Tree tree )
    {
        if ( tree == NULL )
        {
            return;
        }

        printf( "%d, ", tree->data );

        printDepthTraverse( tree->left );
        printDepthTraverse( tree->right );
    }

    template< typename Tree >
    static float calculateProduct( Tree tree )
    {
        if ( tree == NULL )
        {
            return 1.0;
        }

        float product = tree->data;

        product *= calculateProduct( tree->left );
        product *= calculateProduct( tree->right );

        return product;
    }
};

} // typename Tree
} // typename Containers

#endif
