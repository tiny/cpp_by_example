/*
  main.cpp
*/ 
#include <iostream>
#include <stdio.h>
#include <string>
#include <initializer_list>
#include <stdexcept>
#include <cstring>  
#include <memory>

class Point2D
{
  protected:
    float _x ;
    float _y ;

  public:
    Point2D( float x, float y ) : _x( x ), _y( y ) {}
    Point2D operator+( const Point2D& other ) const
    {
      return Point2D( _x + other._x, _y + other._y ) ;
    }
    void print() const
    {
      printf( "  [ %f , %f ]\n\n", _x, _y ) ;
    }
    float x() const { return _x ; }
    float y() const { return _y ; }
    float& x() { return _x ; }
    float& y() { return _y ; }
} ; // class Point2D

class Matrix2D
{
  protected:
    int m_rows ;
    int m_cols ;
    float* m_data ;

  public:
    Matrix2D( int rows, int cols ) : m_rows( rows ), m_cols( cols )
    {
      m_data = new float[ rows * cols ] ; 
    }
    Matrix2D( std::initializer_list<std::initializer_list<double>> rows )
    {
      m_rows = rows.size() ;
      m_cols = rows.begin()->size() ;
      m_data = new float[ m_rows * m_cols ] ;
      float *d = m_data ;
      for( const auto& row : rows )
      {
        for( const auto& value : row )
        {
          *d++ = static_cast<float>( value ) ;
        }
      }
    }
    ~Matrix2D()
    {
      delete[] m_data ;
    }
    float& operator()( int row, int col )
    {
      if ( row < 0 || row >= m_rows || col < 0 || col >= m_cols )
      {
        throw std::out_of_range( "Matrix2D index out of range" ) ;
      }
      return m_data[ row * m_cols + col ] ;
    }
    float& operator()( int row, int col ) const
    {
      if ( row < 0 || row >= m_rows || col < 0 || col >= m_cols )
      {
        throw std::out_of_range( "Matrix2D index out of range" ) ;
      }
      return m_data[ row * m_cols + col ] ;
    }
    float& operator[]( int index )
    {
      if ( index < 0 || index >= m_rows * m_cols )
      {
        throw std::out_of_range( "Matrix2D index out of range" ) ;
      }
      return m_data[ index ] ;
    }
    bool operator==( const Matrix2D& other ) const
    {
      if( m_rows != other.m_rows || m_cols != other.m_cols )
      {
        return false ;
      }
      for( int r = 0 ; r < m_rows ; r++ )
      {
        for( int c = 0 ; c < m_cols ; c++ )
        {
          if( (*this)( r, c ) != other( r, c ) )
          {
            return false ;
          }
        }
      }
      return true ;
    }
    bool operator!=( const Matrix2D& other ) const
    {
      return !( *this == other ) ;
    }
    Matrix2D operator+( const Matrix2D& other ) const
    {
      Matrix2D result( m_rows, m_cols ) ;
      for( int r = 0 ; r < m_rows ; r++ )
      {
        for( int c = 0 ; c < m_cols ; c++ )
        {
          result( r, c ) = (*this)( r, c ) + other( r, c ) ;
        }
      }
      return result ;
    }
    Matrix2D operator*( float scalar ) const
    {
      Matrix2D result( m_rows, m_cols ) ;
      for( int r = 0 ; r < m_rows ; r++ )
      {
        for( int c = 0 ; c < m_cols ; c++ )
        {
          result( r, c ) = (*this)( r, c ) * scalar ;
        }
      }
      return result ;
    }
    Matrix2D operator*( const Matrix2D& other ) const
    {
      Matrix2D result( m_rows, other.m_cols ) ;
      for( int r = 0 ; r < m_rows ; r++ )
      {
        for( int c = 0 ; c < other.m_cols ; c++ )
        {
          result( r, c ) = 0.0f ;
          for( int k = 0 ; k < m_cols ; k++ )
          {
            result( r, c ) += (*this)( r, k ) * other( k, c ) ;
          }
        }
      }
      return result ;
    }
    Matrix2D& operator=( const Matrix2D& other )
    {
      if( this != &other )
      {
        if( m_rows != other.m_rows || m_cols != other.m_cols )
        {
          delete[] m_data ;
          m_rows = other.m_rows ;
          m_cols = other.m_cols ;
          m_data = new float[ m_rows * m_cols ] ;
        }
        memcpy( m_data, other.m_data, m_rows * m_cols * sizeof( float ) ) ;
      }
      return *this ;
    }
    Matrix2D& operator+=( const Matrix2D& other )
    {
      for( int r = 0 ; r < m_rows ; r++ )
      {
        for( int c = 0 ; c < m_cols ; c++ )
        {
          (*this)( r, c ) += other( r, c ) ;
        }
      }
      return *this ;
    }
    Matrix2D& operator*=( float scalar )
    {
      for( int r = 0 ; r < m_rows ; r++ )
      {
        for( int c = 0 ; c < m_cols ; c++ )
        {
          (*this)( r, c ) *= scalar ;
        }
      }
      return *this ;
    }
    Matrix2D& operator*=( const Matrix2D& other )
    {
      *this = (*this) * other ;
      return *this ;
    }
    Matrix2D& operator-=( const Matrix2D& other )
    {
      for( int r = 0 ; r < m_rows ; r++ )
      {
        for( int c = 0 ; c < m_cols ; c++ )
        {
          (*this)( r, c ) -= other( r, c ) ;
        }
      }
      return *this ;
    }
    Matrix2D operator-( const Matrix2D& other ) const
    {
      Matrix2D result( m_rows, m_cols ) ;
      for( int r = 0 ; r < m_rows ; r++ )
      {
        for( int c = 0 ; c < m_cols ; c++ )
        {
          result( r, c ) = (*this)( r, c ) - other( r, c ) ;
        }
      }
      return result ;
    }
    Matrix2D operator/( float scalar ) const
    {
      Matrix2D result( m_rows, m_cols ) ;
      for( int r = 0 ; r < m_rows ; r++ )
      {
        for( int c = 0 ; c < m_cols ; c++ )
        {
          result( r, c ) = (*this)( r, c ) / scalar ;
        }
      }
      return result ;
    }
    Matrix2D& operator/=( float scalar )
    {
      for( int r = 0 ; r < m_rows ; r++ )
      {
        for( int c = 0 ; c < m_cols ; c++ )
        {
          (*this)( r, c ) /= scalar ;
        }
      }
      return *this ;
    }

    Point2D operator*( const Point2D& point ) const
    {
      float x = (*this)( 0, 0 ) * point.x() + (*this)( 0, 1 ) * point.y() ;
      float y = (*this)( 1, 0 ) * point.x() + (*this)( 1, 1 ) * point.y() ;
      return Point2D( x, y ) ;
    }
    Point2D& operator*=( Point2D& point ) const
    {
      point = (*this) * point ;
      return point ;
    }

    void print() const
    {
      for( int r = 0 ; r < m_rows ; r++ )
      {
        printf( "  | " ) ;
        for( int c = 0 ; c < m_cols ; c++ )
        {
          printf( "%4.2f ", (*this)( r, c ) ) ;
        }
        printf( "|\n" ) ;
      }
      printf( "\n" ) ;
    }
} ; // class Matrix2D

int main(int argc, const char *argv[])
{
  printf( "exercising operators\n---\n" ) ;

  printf( "string operators:\n--\n" ) ;
  std::string s1( "hello" ) ;
  std::string s2( "world" ) ; 
  std::string s3 = s1 + ", " + s2 + "!" ;

  std::cout << s3 << std::endl ;

  printf( "\na bit overboard with Matrix2D and Point2D operators:\n--\n" ) ;
  Point2D p1( 1.0f, 2.0f ) ;
  Matrix2D m1 ({ { 2.0f, 0.0f },
                 { 0.0f, 2.0f } }) ;

  p1.print() ;
  m1.print() ;
  Point2D p2 = m1 * p1 ;
  p2.print() ;

  return 0 ;
} // :: main


