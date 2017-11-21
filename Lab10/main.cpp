#include <time.h>
#include <cstdlib>
#include "../Lab6/List.h"

using namespace std;

#define N ( 10 )
#define M ( 10 )

int main()
{
	srand( time( NULL ) );

	Containers::SparseArray< int > sparseArray;

	size_t x = 0;
	size_t y = 0;

	int array[ N ][ M ];

	printf( "The contents of the sparse array are:\r\n" );

	for ( x = 0; x < N; ++x )
	{
		for ( y = 0; y < M; ++y )
		{
			array[ x ][ y ] = rand() % 10;
			printf("x: %lu y: %lu data: %d\r\n", x, y, array[ x ][ y ] );
		}
	}

	printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\r\n\r\n" );
	sparseArray.fillSparseArray< N, M >( array );

	sparseArray.print();
}
