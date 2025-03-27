#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int m_integer;
		static constexpr const int m_FRACTION_BITS = 8;
	
	public:
		Fixed();
		Fixed(const Fixed& other);

		~Fixed();

		// Operator overloads
		Fixed& operator=(const Fixed& other);

		// FUNCTIONS
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
