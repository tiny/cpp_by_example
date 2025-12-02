/*
  main.cpp
*/ 
#include <stdio.h>

int sum_array( const int arr[], int size )
{
    int total = 0 ;
    for( int i = 0 ; i < size ; i++ )
    {
        total += arr[i] ;
    } // for i
    return total ;
} // :: sum_array

float avg_array( const int arr[], int size )
{
    if( size == 0 ) return 0.0f ;
    int total = sum_array( arr, size ) ;
    return float(total) / float(size) ;
} // :: avg_array

#define NUM_ELEMENTS 6

int main(int argc, const char *argv[])
{
  printf( "Array of integers in C++\n---\n" ) ;

  int data[NUM_ELEMENTS] = { 10, 20, 30, 40, 50, 60 } ;
  for( int i = 0 ; i < NUM_ELEMENTS ; i++ )
  {
      printf( "  data[%d] = %d\n", i, data[i] ) ;
  } // for i

  printf( "\n" ) ;

  printf( "  size: %d\n", NUM_ELEMENTS ) ;
  
  int total = sum_array( data, NUM_ELEMENTS ) ;
  printf( "  sum : %d\n", total ) ;

  float average = avg_array( data, NUM_ELEMENTS ) ;
  printf( "  avg : %.2f\n", average ) ;

  printf( "\n" ) ;
  return 0 ;
} // :: main


