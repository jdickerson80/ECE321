#include <stdio.h>
#include "../Lab6/List.h"

typedef Containers::DLList< int > IntDLLList;

int main()
{
	FILE* inFile = fopen( "../ECE321Repo/Lab11/INFILE.txt", "r" );
	FILE* outFile = fopen( "../ECE321Repo/Lab11/OUTFILE.txt", "w" );

	if ( !inFile )
	{
		printf( "Cannot open the input file.\r\n" );
		return -1;
	}

	IntDLLList intList;

	int input;

	while ( fscanf( inFile, "%d", &input ) != EOF )
	{
		intList.insert( input );
	}

	intList.print();

	bool first = true;

	while ( !intList.isEmpty() )
	{
		if ( first )
		{
			fprintf( outFile, "%d\r\n", intList.first()->data() );
			intList.popFront();
		}
		else
		{
			fprintf( outFile, "%d\r\n", intList.last()->data() );
			intList.popRear();
		}

		first = !first;
	}
}
