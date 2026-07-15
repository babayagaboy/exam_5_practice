#include "vect2.hpp"

vect2::vect2( void ) : _x(0), _y(0)
{
}

vect2::vect2( int x, int y ) : _x(x), _y(y)
{
}

vect2::vect2( const vect2& other )
{
	*this = other;
}

vect2& vect2::operator=( const vect2& other )
{
	if(this != &other)
	{
		this->_x = other._x;
		this->_y = other._y;
	}
	return(*this);
}

vect2::~vect2( void )
{
}


vect2 vect2::operator++()
{
	vect2 temp(*this);
	this->_x++;
	this->_y++;
	return(temp);
}

vect2& vect2::operator++( int )
{
	this->_x++;
	this->_y++;
	return(*this);
}


vect2 vect2::operator--()
{
	vect2 temp(*this);
	this->_x--;
	this->_y--;
	return(temp);
}

vect2& vect2::operator--( int )
{
	this->_x--;
	this->_y--;
	return(*this);
}


vect2 vect2::operator-()
{
	return(vect2(-(this->_x), -(this->_y)));
}


vect2 vect2::operator+( const vect2& other ) const
{
	return(vect2((this->_x + other._x), (this->_y + other._y)));
}

vect2 vect2::operator-( const vect2& other ) const
{
	return(vect2((this->_x - other._x), (this->_y - other._y)));
}

vect2 vect2::operator*( const vect2& other ) const
{
	return(vect2((this->_x + other._x), (this->_y + other._y)));
}

vect2 vect2::operator*( int num ) const
{
	return(vect2((this->_x * num), (this->_y * num)));
}


vect2& vect2::operator+=( const vect2& other )
{
	this->_x = this->_x + other._x;
	this->_y = this->_y + other._y;
	return(*this);
}

vect2& vect2::operator-=( const vect2& other )
{
	this->_x = this->_x - other._x;
	this->_y = this->_y - other._y;
	return(*this);
}

vect2& vect2::operator*=( const vect2& other )
{
	this->_x = this->_x * other._x;
	this->_y = this->_y * other._y;
	return(*this);
}

vect2& vect2::operator*=( int num )
{
	this->_x = this->_x * num;
	this->_y = this->_y * num;
	return(*this);
}


bool vect2::operator==( const vect2& other ) const
{
	return((this->_x == other._x) && (this->_y == other._y));
}

bool vect2::operator!=( const vect2& other ) const
{
	return((this->_x != other._x) || (this->_y != other._y));
}


int&	vect2::operator[]( int idx )
{
	if(idx == 0) { return(this->_x); }
	return(this->_y);
}

int	vect2::operator[]( int idx ) const
{
	if(idx == 0) { return(this->_x); }
	return(this->_y);
}

vect2 operator*( int num, vect2& other )
{
	vect2 temp(other);
	temp *= num;
	return(temp);
}

std::ostream& operator<<( std::ostream& o, const vect2& v)
{
	o << "{" << v[0] << ", " << v[1] << "}";
	return(o);
}
