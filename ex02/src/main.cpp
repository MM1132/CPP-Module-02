#include <iostream>

#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	/*
	?	0
	?	0.00390625
	?	0.00390625
	?	0.00390625
	?	0.0078125
	?	10.1016
	?	10.1016
	*/

	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// a++;
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	// Fixed myFixed = Fixed(0.0f);
	// myFixed++;
	// std::cout << "My fixed: " << ++myFixed << std::endl;

	return 0;
}

/*
0
0
0.00390625
0.00390625
0.00390625
10.1016
10.1016
*/