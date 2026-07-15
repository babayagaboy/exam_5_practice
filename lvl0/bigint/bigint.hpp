






#ifndef BIGINT_HPP
# define BIGINT_HPP

#include <sstream>
#include <iostream>

class bigint {
	private:
		std::string	_num;
	public:
		bigint( void );
		bigint( unsigned int num );
		bigint( std::string num );
		bigint( const bigint& other );
		~bigint();
		
		std::string getNum() const;
		unsigned int strToInt( void ) const;

		bigint& operator=( const bigint& other );
		bigint operator+( const bigint& other ) const;
		bigint& operator+=( const bigint& other );

		bigint& operator++(); //++x
		bigint operator++( int ); //x++

		bigint operator<<( unsigned int n );
		bigint operator>>( unsigned int n );

		bigint& operator<<=( unsigned int n );
		bigint& operator>>=( unsigned int n );

		bigint operator<<( const bigint& other );
		bigint operator>>( const bigint& other );

		bigint& operator<<=( const bigint& other );
		bigint& operator>>=( const bigint& other );

		bool operator>( const bigint& other ) const;
		bool operator<( const bigint& other ) const;
		bool operator<=( const bigint& other ) const;
		bool operator>=( const bigint& other ) const;
		bool operator==( const bigint& other ) const;
		bool operator!=( const bigint& other ) const;

};

std::ostream& operator<<(std::ostream& o, const bigint& bi);

#endif