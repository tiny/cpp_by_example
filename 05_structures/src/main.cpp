/*
  main.cpp
*/ 
#include <stdio.h>
#include <math.h>

struct Point
{
    int   x ;
    int   y ;

    Point( int a, int b ) : x(a), y(b) {}
} ; // struct Point

float distance( const Point &p1, const Point &p2 )
{
    int dx = p2.x - p1.x ;
    int dy = p2.y - p1.y ;
    return sqrtf( float(dx*dx + dy*dy) ) ;
} // :: distance

int main(int argc, const char *argv[])
{
  printf( "Structures in C++\n---\n" ) ;

  Point p1( 10, 20 ) ;
  Point p2( 30, 40 ) ;

  printf( "  Point 1: (%d, %d)\n", p1.x, p1.y ) ;
  printf( "  Point 2: (%d, %d)\n", p2.x, p2.y ) ;

  float dist = distance( p1, p2 ) ;
  printf( "  Distance between p1 and p2: %.2f\n", dist ) ;
  printf( "\n" ) ;

  return 0 ;
} // :: main


