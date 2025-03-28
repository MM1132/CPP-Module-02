#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int m_integer;
		static constexpr const int m_FRACTION_BITS = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int number);
		Fixed(const float number);

		~Fixed();

		// Operator overloads
		Fixed& operator=(const Fixed& other);

		// FUNCTIONS
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		
		// Operators
		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

		// >, <, >=, <=, ==, and !=
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;

		// +, -, *, and /
		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);

		// -- and ++
		Fixed operator--(int);
		Fixed operator++(int);
		Fixed& operator--();
		Fixed& operator++();

		static Fixed& min(Fixed& first, Fixed& second);
		static const Fixed& min(const Fixed& first, const Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);
};

#endif
