#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "Music.h"

Complex::Complex() {}

Complex::Complex(double Re, double Im) {
	_Re = Re;
	_Im = Im;
}

Complex::Complex(double Re) {
	_Re = Re;
	_Im = 0;
}

Complex Complex::operator+(const Complex &right) const {
	return Complex(_Re + right._Re, _Im + right._Im);
}

Complex Complex::operator-(const Complex &right) const {
	return Complex(_Re - right._Re, _Im - right._Im);
}

Complex Complex::operator*(const Complex &right) const {
	return Complex(_Re * right._Re - _Im * right._Im, _Re * right._Im + _Im * right._Re);
}

Complex Complex::operator/(const double right) const {
	return Complex(_Re / right, _Im / right);
}

Complex Complex::operator^(const double alpha) const {
	return Complex(_Re * cos(alpha) - _Im * sin(alpha), _Im * cos(alpha) + _Re * sin(alpha));
}

std::ostream &operator<<(std::ostream &output, const Complex &comp) {
	output << std::fixed << std::setprecision(3) << comp._Re << '+' << std::fixed << std::setprecision(3) << comp._Im << 'i';
	return output; 	
}

std::istream &operator>>(std::istream &input, Complex &comp) {
	input >> comp._Re >> comp._Im;
	return input;
}

std::vector<Complex> parse(std::string str) {
	std::vector<Complex> vec;
	for (int i = 44; i < str.size(); ++i) {
		vec.push_back(Complex((double)str[i]));
	}
	return vec;
}

void ft(std::vector<Complex> &vec, bool invers) {
	std::vector<Complex> copy = vec;
	for (int k = 0; k < copy.size(); ++k) {
		Complex sum(0, 0);
		for (int j = 0; j < copy.size(); ++j) {
			sum = sum + (copy[j] ^ ((2 * M_PI * j * k * (invers ? -1: 1)) / copy.size()));
		}
		vec[k] = sum;
		if (invers) {
			vec[k] = vec[k] / vec.size();
		}
	}
}

void fft(std::vector<Complex> &vec_f, bool invert) {
	int n = (int) vec_f.size();
	if (n == 1) {
		return;
	}
	std::vector<Complex> even_vec(n / 2), uneven_vec(n / 2);
	for (int i = 0, j = 0; i < n; i += 2, ++j) {
		even_vec[j] = vec_f[i];
		uneven_vec[j] = vec_f[i + 1];
	}
	fft(even_vec, invert);
	fft(uneven_vec, invert);
	double alpha = 2 * M_PI / n * (invert ? -1: 1);
	for (int i = 0; i < n / 2; ++i) {
		vec_f[i] = even_vec[i] + (uneven_vec[i] ^ (alpha * i));
		vec_f[n / 2 + i] = even_vec[i] - (uneven_vec[i] ^ (alpha * i));
		if (invert) {
			vec_f[i] = vec_f[i] / 2, vec_f[n / 2 + i] = vec_f[n / 2 + i] / 2;
		}
	}
}


int find_max_2_power(int N) {
	int tmp = 1;
	while (N > tmp) {
		tmp *= 2;
	}
	return tmp;
}
