/*
  main.cpp
*/ 
#include <stdio.h>

int get_value( const char *prompt )
{
    int value = 0 ;
    printf( "%s", prompt ) ;
    scanf( "%d", &value ) ;
    return value ;
} // :: getstdinteger

int double_value( int val )
{
    return val * 2 ;
} // :: double_value

void show_value( const char *prompt, int val )
{
    printf( "%s: %d\n", prompt, val ) ;
} // :: show_value

int main(int argc, const char *argv[])
{
  int x, y ;

  printf( "Function Example\n---\n" ) ;
  x = get_value( "Enter integer: " ) ;
  show_value( "value is", x ) ;
  y = double_value( x ) ;
  show_value( "doubled value is", y ) ;
  printf( "\n" ) ;

  return 0 ;
} // :: main


