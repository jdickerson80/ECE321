#ifndef TREE_H
#define TREE_H

#include <cstdlib>
#include <algorithm>

namespace Containers {

template< typename DataType >
struct TreeNode
{
	DataType data;
	TreeNode* left;
	TreeNode* right;

	TreeNode()
		: data( 0 )
		, left( NULL )
		, right( NULL )
	{}

	TreeNode( DataType data, TreeNode* left = NULL, TreeNode* right = NULL )
		: data( data )
		, left( left )
		, right( right )
	{}
};


struct TreeHelperFunctions
{
private:

	TreeHelperFunctions();

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

	template< typename Tree, typename DataType >
	static void balancedTreeInsert( Tree tree, DataType data )
	{
		if ( tree == NULL )
		{
			tree = new TreeNode< DataType >( data );
		}
		else
		{
			int leftSize = depth( tree->left );
			int rightSize = depth( tree->right );

			if ( leftSize <= rightSize )
			{
				balancedTreeInsert( tree->left, data );
			}
			else
			{
				balancedTreeInsert( tree->right, data );
			}
		}
	}
};

} // typename Containers
#endif
