#include <iostream>
#include "rational.hpp"


Rational::Rational (int n, int d) : numerator(n), denominator(d){
	if (d == 0) d == 1;
	this->simplify();
}


void Rational::operator+= (Rational const& b){
	numerator = numerator * b.denominator + b.numerator * denominator;
	denominator *= b.denominator;
}

void Rational::operator-= (Rational const& b){
	numerator = numerator * b.denominator - b.numerator * denominator;
	denominator *= b.denominator;
}

void Rational::operator*= (Rational const& b){
	numerator = numerator * b.numerator;
	denominator = denominator * b.denominator;
}

void Rational::operator/= (Rational const& b){
	numerator = numerator * b.denominator;
	denominator = denominator * b.numerator;
}

int Rational::getNumerator() const{
	return numerator;
}

int Rational::getDenominator() const{
	return denominator;
}

void Rational::inputNumerator(int num){
	numerator = num;
}

void Rational::inputDenominator(int den){
	denominator = den;
}

Rational operator+ (Rational const& a, Rational const& b){
	Rational answer(a);
	answer += b;
	answer.simplify();
	return answer;
}


Rational operator- (Rational const& a, Rational const& b){
	Rational answer(a);
	answer -= b;
	answer.simplify();
	return answer;
}

Rational operator* (Rational const& a, Rational const& b){
	Rational answer(a);
	answer *= b;
	answer.simplify();
	return answer;
}

Rational operator/ (Rational const&a, Rational const& b){
	Rational answer(a);
	answer /= b;
	answer.simplify();
	return answer;
}


int GCD (int a, int b){
	if (b == 0) return a;
	return GCD (b, a%b);
}

void Rational::simplify(){
	int greatestCommonDevisor = GCD(denominator, numerator);
	numerator /= greatestCommonDevisor;
	denominator /= greatestCommonDevisor;

	if (denominator < 0){
		numerator = -numerator;
		denominator = -denominator;
	}
}

Rational::operator float(){
	return static_cast<float>(numerator) / denominator;
}

Rational::operator double(){
	return static_cast<double>(numerator) / denominator;
}

bool operator< (Rational const& a, Rational const& b){
	return a.getNumerator() * b.getDenominator() < b.getNumerator() * a.getDenominator();
}

bool operator<= (Rational const& a, Rational const& b){
	return a.getNumerator() * b.getDenominator() <= b.getNumerator() * a.getDenominator();
}

bool operator> (Rational const& a, Rational const& b){
	return b < a;
}

bool operator>=  (Rational const& a, Rational const& b){
	return b <= a;
}

bool operator== (Rational const& a, Rational const& b){
	return (a.getNumerator() == b.getNumerator() && a.getDenominator() == b.getDenominator());
}

bool operator!= (Rational const& a, Rational const& b){
	return !(a==b);
}

std::istream& operator>> (std::istream& i, Rational& a){
	int c = 0;
	char b = ' ';
	i >> c;
	a.inputNumerator(c);
	i >> b;
	i >> c;
	if (c != 0){
		a.inputDenominator(c);
	} else {
		a.inputDenominator(1);
	}
	a.simplify();
	return i;
}

std::ostream& operator<< (std::ostream& o, Rational const& a){
	o << a.getNumerator() << "/" << a.getDenominator();
}

