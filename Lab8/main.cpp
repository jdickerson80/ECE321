#include "Tree.h"
#include "stdio.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
	srand( time( NULL ) );

	Containers::Tree::Node< int >* tree = NULL;

	int loop = 0;

	for ( ; loop < 4; ++loop )
	{
		Containers::Tree::Functions::balancedTreeInsert( &tree, rand() % 10 );
	}

	printf( "The depth traverse printing of the tree is: \r\n" );

	Containers::Tree::Functions::printDepthTraverse( tree );

	printf("\r\n");

	printf("The depth of the tree is %d.\r\n", Containers::Tree::Functions::depth( tree ) );

	printf("The product of the tree is %2.2f\r\n", Containers::Tree::Functions::calculateProduct( tree ) );
}
