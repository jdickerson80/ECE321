#include "Tree.h"
#include "stdio.h"
using namespace std;

int main()
{
	typedef Containers::TreeNode< int >* Tree;

	Tree tree;

	int loop = 0;

	for ( ; loop < 10; ++loop )
	{
		// this is a change
		Containers::TreeHelperFunctions::balancedTreeInsert( tree, loop );
	}


	printf(" depth is %d\r\n", Containers::TreeHelperFunctions::depth( tree ) );
	return 0;
}
