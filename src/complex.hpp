#ifndef COMPLEX_HPP_INCLUDED
#define COMPLEX_HPP_INCLUDED

class Complex
{
public:
    //Конструктор та деструктор
	Complex();
	Complex(double, double);
	~Complex() = default;

	//Задаємо значення
	void setReal(const double&);
	void setImag(const double&);

	//Стандартні операції з комплексними числами
	Complex operator+(const Complex&) const;
	Complex operator-(const Complex&) const;
	Complex operator*(const Complex&) const;
	Complex operator/(const Complex&) const;

	Complex operator+(const double&) const;
	Complex operator-(const double&) const;
	Complex operator*(const double&) const;
	Complex operator/(const double&) const;

	friend Complex operator+(const double&, const Complex&);
	friend Complex operator-(const double&, const Complex&);
	friend Complex operator*(const double&, const Complex&);
	friend Complex operator/(const double&, const Complex&);

	void operator+=(const Complex&);
	void operator-=(const Complex&);
	void operator*=(const Complex&);
	void operator/=(const Complex&);

	void operator+=(const double&);
	void operator-=(const double&);
	void operator*=(const double&);
	void operator/=(const double&);

	friend std::ostream& operator<<(std::ostream&, const Complex&);
	friend std::istream& operator>>(std::istream&, Complex&);

	double getReal() const;
	double getImag() const;
protected:
    double real = 0, imag = 0;
};

#endif // COMPLEX_HPP_INCLUDED
