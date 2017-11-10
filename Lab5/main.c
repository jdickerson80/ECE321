#include <stdio.h>
#include <stdlib.h>

#define true ( 1 )

int main()
{
	int n = 0;

	while( true )
	{
		printf("Enter a number greater than 5 and smaller than 10: ");
		scanf( "%d", &n );

		if ( n > 5 && n < 10 )
		{
			break;
		}
	}

	int* array = malloc( n * sizeof( int ) );


	int i = 0;

	for ( ; i < n; ++i )
	{
		printf( "Enter a value for the index %d: ", i );
		scanf( "%d", &array[ i ] );
	}

	printf( "The values entered are: " );

	for ( i = 0; i < n; ++i )
	{
		printf( "%d, ", array[ i ] );
	}

	printf( "\r\n" );

	free( array );
	return 0;
}
