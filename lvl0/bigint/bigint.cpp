#include "bigint.hpp"

bigint::bigint( void )
{
}

bigint::bigint( unsigned int num )
{
	std::stringstream ss;
	ss << num;
	this->_num = ss.str();
}

unsigned int bigint::strToInt( void ) const
{
	std::stringstream ss;
	unsigned int num;
	ss << this->_num;
	ss >> num;
	return(num);
}

bigint::bigint( std::string num )
{
	this->_num = num;
}

bigint::bigint( const bigint& other ) : _num(other._num)
{
}

bigint::~bigint()
{
}

std::string bigint::getNum() const
{
	return(this->_num);
}


bigint& bigint::operator=( const bigint& other )
{
	if (this != &other)
	{
		this->_num = other._num;
	}
	return (*this);
}
bigint bigint::operator+(const bigint& other) const
{
	std::string result = "";
	int i = this->_num.size() - 1;
	int j = other._num.size() - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry > 0)
	{
		int sum = carry;

		if (i >= 0) {
			sum += (this->_num[i] - '0');
			i--;
		}

		if (j >= 0) {
			sum += (other._num[j] - '0'); 
			j--;
		}

		carry = sum / 10;
		result.insert(result.begin(), (sum % 10) + '0');
	}
	return bigint(result);
}

bigint& bigint::operator+=( const bigint& other )
{
	*this = *this + other;
	return(*this);
}

bigint& bigint::operator++()
{
	*this = *this + bigint(1);
	return(*this);
}

bigint bigint::operator++( int )
{
	bigint temp(*this);
	*this = *this + bigint(1);
	return(temp);
}

bigint bigint::operator<<( unsigned int n )
{
	bigint temp(*this);
	for(int i = 0; i < n; ++i)
		temp._num.push_back('0');
	return(temp);
}

bigint bigint::operator>>( unsigned int n )
{
	bigint temp(*this);
	for(int i = 0; i < n; ++i)
		temp._num.erase(temp._num.size() - i - 1);
	return(temp);
}

bigint& bigint::operator<<=( unsigned int n )
{
	*this = *this << n;
	return(*this);
}

bigint& bigint::operator>>=( unsigned int n )
{
	*this = *this >> n;
	return(*this);
}

bigint bigint::operator<<( const bigint& other )
{
	bigint temp(*this);
	*this = *this << other.strToInt();
	return(*this);
}

bigint bigint::operator>>( const bigint& other )
{
	bigint temp(*this);
	*this = *this >> other.strToInt();
	return(*this);
}

bigint& bigint::operator<<=( const bigint& other )
{

	*this = *this << other.strToInt();
	return(*this);
}

bigint& bigint::operator>>=( const bigint& other )
{
	*this = *this >> other.strToInt();
	return(*this);
}

bool bigint::operator>( const bigint& other ) const
{
	return(this->_num > other._num);
}

bool bigint::operator<( const bigint& other ) const
{
	return(this->_num < other._num);
}

bool bigint::operator<=( const bigint& other ) const
{
	return(this->_num <= other._num);
}

bool bigint::operator>=( const bigint& other ) const
{
	return(this->_num >= other._num);
}

bool bigint::operator==( const bigint& other ) const
{
	return(this->_num == other._num);
}

bool bigint::operator!=( const bigint& other ) const
{
	return(this->_num != other._num);
}


std::ostream& operator<<(std::ostream& o, const bigint& bi)
{
	o << bi.getNum();
	return (o);
}
