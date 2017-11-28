#ifndef RATIONAL_NUMBERS_HPP
#define RATIONAL_NUMBERS_HPP

#include <iostream>

class Rational{

	public:
	
		Rational(int numerator = 0, int denominator = 1);
		void operator+= (Rational const& a);
		void operator-= (Rational const& a);
		void operator*= (Rational const& a);
		void operator/= (Rational const& a);

		int getNumerator() const;
		int getDenominator() const;
		void inputNumerator(int numerator);
		void inputDenominator(int denominator);
		void simplify();

		operator float();
		operator double();

	private:
		int numerator;
		int denominator;
};

Rational operator+ (Rational const& a, Rational const& b);
Rational operator- (Rational const& a, Rational const& b);
Rational operator* (Rational const& a, Rational const& b);
Rational operator/ (Rational const& a, Rational const& b);

bool operator< (Rational const& a, Rational const& b);
bool operator<= (Rational const& a, Rational const& b);
bool operator> (Rational const& a, Rational const& b);
bool operator>= (Rational const& a, Rational const& b);
bool operator== (Rational const& a, Rational const& b);
bool operator!= (Rational const& a, Rational const& b);

std::istream& operator>> (std::istream& i, Rational & a);
std::ostream& operator<< (std::ostream&, Rational const &);


//operator double(){
//return static_cast<double>(n) / double;
//}


#endif
