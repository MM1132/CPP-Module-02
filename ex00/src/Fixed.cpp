#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed()
: m_integer(0)
{
	std::cout << "Default constructor called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;

	return m_integer;
}

void Fixed::setRawBits(int const raw)
{
	m_integer = raw;
}
