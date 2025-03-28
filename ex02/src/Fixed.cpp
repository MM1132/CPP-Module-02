#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed()
: m_integer(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
: m_integer(number << m_FRACTION_BITS)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
: m_integer(roundf(number * (1 << m_FRACTION_BITS)))
{
	std::cout << "Float constructor called" << std::endl;
}

// This is our Copy Constructor!! Yey! :) 
Fixed::Fixed(const Fixed& other)
: m_integer(other.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	// Check if we have passed the same object into the = opeartor
	// ...in which case changing anything would be useless
	if (this != &other)
	{
		m_integer = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// FUNCTIONS
int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;

	return m_integer;
}

void Fixed::setRawBits(int const raw)
{
	m_integer = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->getRawBits() / (1 << m_FRACTION_BITS);
}

int Fixed::toInt(void) const
{
	return m_integer >> m_FRACTION_BITS;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}

// OPERATORS
// >, <, >=, <=, ==, and !=
bool Fixed::operator==(const Fixed& other) const
{
	return this->toFloat() == other.toFloat();
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->toFloat() < other.toFloat();
};

bool Fixed::operator>=(const Fixed& other) const
{
	return *this > other || *this == other;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return *this < other || *this == other;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return !(*this == other);
}

// +, -, *, and /
Fixed Fixed::operator+(const Fixed& other)
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other)
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other)
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other)
{
	return Fixed(this->toFloat() / other.toFloat());
}

// -- and ++
Fixed Fixed::operator--(int)
{
	// std::cout << "Post-- called" << std::endl;
	Fixed tmp = *this;
	this->m_integer = this->getRawBits() - 1;
	return tmp;
}

Fixed Fixed::operator++(int)
{
	// std::cout << "Post++ called" << std::endl;
	Fixed tmp = *this;
	this->m_integer = this->getRawBits() + 1;
	return tmp;
}

Fixed& Fixed::operator--()
{
	this->m_integer = this->getRawBits() - 1;
	return *this;
}

Fixed& Fixed::operator++()
{
	this->m_integer = this->getRawBits() + 1;
	return *this;
}

// The static functions
Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	return first < second ? first : second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	return first < second ? first : second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	return first > second ? first : second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	return first > second ? first : second;
}
