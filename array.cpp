//array.cpp
#include <iostream> 
#include <vector>
using namespace std;

/**
*@brief prints the elements in the array and their memory locations
*
*@param arr - array of int 
*@param size - number of elements in the array
*/ 
void printMemArr( const int arr[ ], int size ) 
{ // void printMem (const int * arr, int size )
printf("Array - Each in is int worth %lu bytes\n" , sizeof(arr[0])) ;
for ( int i = 0 ; i< size ; i++) {
    printf ("value %i at memory Locations %p\n" , arr [ i ] , arr + i );
    }
}

/** 
* @brief increments all of the elements in the arr by 10 
*
*@param arr - array of int 
* @param size  - number of elements in the array 
*/
void incArrBy10 (int arr[ ] , int size ) 
{ // void incArrBy10 (int *arr, int size 
	for( int i = 0; i < size; i++) 
    {
	arr [ i ] += 10;
	}
}

int main () 
{
	const int SIZE = 5 ;
	int arr [SIZE] ; 
	for (int i = 0; i< SIZE ; i++) 
    {
	arr [ i ] = 100 + i;
    }

printf ("Before —---------------\n");
printMemArr ( arr, SIZE ) ; 

//change the value 
incArrBy10 (arr , SIZE) ; 
printf ( "After—---------------\n") ;
printMemArr( arr, SIZE ) ;
return 0;
}
