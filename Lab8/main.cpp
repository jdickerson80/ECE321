#include "Tree.h"
#include "stdio.h"
using namespace std;

int main()
{

	Containers::TreeNode< int >* tree = NULL;

	int loop = 0;

	for (; loop < 10; ++loop)
	{
		// this is a change
		Containers::TreeHelperFunctions::balancedTreeInsert(&tree, loop);
	}


	printf(" depth is %d\r\n", Containers::TreeHelperFunctions::depth(tree));

	Containers::TreeHelperFunctions::printDepthTraverse(tree);

	scanf("%d", &loop);
}
