#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include "../Lab6/List.h"

using namespace std;


int main()
{
	srand( time( NULL ) );

	int input;

	FILE* fin = fopen( "INFILE.txt", "r" );
//	FILE* fout = fopen( "INFILE.txt", "w" );

	printf("%p\r\n", fin );

	fscanf( fin, "%d", &input );

	printf("%d\r\n", input );
}
