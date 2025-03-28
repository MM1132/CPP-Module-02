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
		
		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif
