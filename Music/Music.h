#include <iostream>
#include <vector>

struct Complex {
	double _Re, _Im;
	Complex();
	Complex(double Re);
	Complex(double Re, double Im);
	Complex operator+(const Complex &right) const;
	Complex operator-(const Complex &right) const;
	Complex operator*(const Complex &right) const;
	Complex operator/(const double right) const;
	Complex operator^(const double alpha) const;
	friend std::ostream &operator<<(std::ostream &output, const Complex &comp);
	friend std::istream &operator>>(std::istream &input, Complex &comp);
};
void ft(std::vector<Complex> &vec, bool invers);

void fft(std::vector<Complex> &vec_f, bool invert);

int find_max_2_power(int N);

std::vector<Complex> parse(std::string str);
