#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include "complex.hpp"

using namespace std;

double abs(double& value)
{
	return (value > 0 ? value : -value);
}

// Ініціалізація

Complex::Complex() :real(0), imag(0) {}
Complex::Complex(double real, double imag = 0) : real(real), imag(imag) {}


// Змінюємо значення комплексного числа

void Complex::setReal(const double& real)
{
	this->real = real;
}
void Complex::setImag(const double& imag)
{
	this->imag = imag;
}


// Оператори

Complex Complex::operator+(const Complex& complex) const
{
	return Complex((this->real + complex.real), (this->imag + complex.imag));
}
Complex Complex::operator-(const Complex& complex) const
{
	return Complex((this->real - complex.real), (this->imag - complex.imag));
}
Complex Complex::operator*(const Complex& complex) const
{
	return Complex((this->real * complex.real - this->imag * complex.imag), (this->real * complex.imag + this->imag * complex.real));
}
Complex Complex::operator/(const Complex& complex) const
{
	return Complex((this->real * complex.real + this->imag * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag), (this->imag * complex.real - this->real * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag));
}


Complex Complex::operator+(const double& number) const
{
	return Complex((this->real + number), this->imag);
}
Complex Complex::operator-(const double& number) const
{
	return Complex((this->real - number), this->imag);
}
Complex Complex::operator*(const double& number) const
{
	return Complex((this->real * number), this->imag * number);
}
Complex Complex::operator/(const double& number) const
{
	return Complex((this->real / number), this->imag / number);
}


Complex operator+(const double& number, const Complex& complex)
{
	return Complex((number + complex.real), complex.imag);
}
Complex operator-(const double& number, const Complex& complex)
{
	return Complex((number - complex.real), complex.imag);
}
Complex operator*(const double& number, const Complex& complex)
{
	return Complex((number * complex.real), number * complex.imag);
}
Complex operator/(const double& number, const Complex& complex)
{
	return Complex((number * complex.real) / (complex.real * complex.real + complex.imag * complex.imag), (number * -complex.imag) / (complex.real * complex.real + complex.imag * complex.imag));
}


void Complex::operator+=(const Complex& complex)
{
	this->real = (this->real + complex.real);
	this->imag = (this->real + complex.imag);
}
void Complex::operator-=(const Complex& complex)
{
	this->real = (this->real - complex.real);
	this->imag = (this->real - complex.imag);
}
void Complex::operator*=(const Complex& complex)
{
	double temp_real = (this->real * complex.real - this->imag * complex.imag);
	double temp_imag = (this->real * complex.imag + this->imag * complex.real);
	this->real = temp_real;
	this->imag = temp_imag;
}
void Complex::operator/=(const Complex& complex)
{
	double temp_real = ((this->real * complex.real + this->imag * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag));
	double temp_imag = ((this->imag * complex.real - this->real * complex.imag) / (complex.real * complex.real + complex.imag * complex.imag));
	this->real = temp_real;
	this->imag = temp_imag;
}


void Complex::operator+=(const double& value)
{
	this->real = (this->real + value);
}
void Complex::operator-=(const double& value)
{
	this->real = (this->real - value);
}
void Complex::operator*=(const double& value)
{
	this->real = (this->real * value);
	this->imag = (this->imag * value);
}
void Complex::operator/=(const double& value)
{
	this->real = (this->real / value);
	this->imag = (this->imag / value);
}



std::ostream& operator<<(std::ostream& os, const Complex& complex)
{
	if (complex.imag == 0.0)
	{
		os << complex.real << "";
		return os;
	}
	if (complex.real == 0.0)
	{
		if (abs(complex.imag) == 1.0)
		{
			os << (complex.imag > 0 ? "" : "-") << "i";
			return os;
		}
		else
		{
			os << complex.imag << "i";
			return os;
		}
	}
	if (abs(complex.imag) == 1.0)
	{
		os << complex.real << ((complex.imag > 0.0) ? "+" : "-") << "i";
		return os;
	}
	std::cout << complex.real << ((complex.imag > 0.0) ? "+" : "") << complex.imag << "i";
	return os;
}


std::istream& operator>>(std::istream& is, Complex& complex)
{
	is >> complex.real;
	is >> complex.imag;
	return is;
}


// Отримуємо значення комплексних чисел

double Complex::getReal() const
{
	return real;
}

double Complex::getImag() const
{
	return imag;
}

