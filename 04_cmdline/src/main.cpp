/*
  main.cpp
*/ 
#include <stdio.h>

int main(int argc, const char *argv[])
{
  printf( "\nCommand Line Parameters Example\n---\n" ) ;
  printf( "there are %d parameters\n", argc ) ;
  for( int i = 0 ; i < argc ; i++ )
  {
      printf( "  parameter %d. [%s]\n", i, argv[i] ) ;
  }
  printf( "\n" ) ;
  return 0 ;
} // :: main


