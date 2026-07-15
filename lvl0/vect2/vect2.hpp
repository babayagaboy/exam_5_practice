#ifndef VECT2_HPP
# define VECT2_HPP

#include <iostream>
#include <sstream>

class vect2 {
	private:
		int	_x;
		int	_y;
	public:
		vect2( void );
		vect2( int x, int y );
		vect2( const vect2& other );
		vect2& operator=( const vect2& other );
		~vect2( void );

		vect2 operator++();
		vect2& operator++( int );
		
		vect2 operator--();
		vect2& operator--( int );

		vect2 operator-();

		vect2 operator+( const vect2& other ) const;
		vect2 operator-( const vect2& other ) const;
		vect2 operator*( const vect2& other ) const;
		vect2 operator*( int num ) const;

		vect2& operator+=( const vect2& other );
		vect2& operator-=( const vect2& other );
		vect2& operator*=( const vect2& other );
		vect2& operator*=( int num );

		bool operator==( const vect2& other ) const;
		bool operator!=( const vect2& other ) const;

		int& operator[]( int idx );
		int	operator[]( int idx ) const;
};

vect2 operator*( int num, vect2& other );

std::ostream& operator<<( std::ostream& o, const vect2& v );

#endif