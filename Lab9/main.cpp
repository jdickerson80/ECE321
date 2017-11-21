#include <iostream>
#include <time.h>
#include <cstdlib>
#include "../Lab8/Tree.h"

using namespace std;

#define NumberOfTreeInsertions ( 10 )

int main()
{
	srand( time( NULL ) );

	Containers::Tree::Node< int >* bst = NULL;

	int loop = 0;

	for ( ; loop < NumberOfTreeInsertions; ++loop )
	{
		int data = rand() % 10;
		Containers::Tree::Functions::binarySearchTreeInsert( &bst, data );
	}

	printf( "The depth traverse printing of the bst is: \r\n" );

	Containers::Tree::Functions::printDepthTraverse( bst );

	printf("\r\n");
	printf("The number of leaves in the tree is %d.\r\n", Containers::Tree::Functions::numberOfLeaves( bst ) );
}
