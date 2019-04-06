#include <iostream>
#include <vector>
#include <fstream>
#include "Music/Music.h"

void equalizer(std::vector<Complex> &vec, double factor) {
	for (int i = 1; i < vec.size() / 2; ++i) {
		vec[i] = vec[i] * (factor * (i - vec[(vec.size() / 2 - 1) / 2]._Re) + 1);
	}
	for (int i = vec.size() / 2 + 1; i < vec.size(); ++i) {
		vec[i] = vec[i - vec.size() / 2];
	}
}

int main(int argc, char **argv) {
	std::fstream music(argv[1]);
	std::fstream output(argv[4], std::fstream::out | std::fstream::in | std::fstream::trunc | std::fstream::binary);
	std::string str = "";
	std::vector<Complex> vec, copy;
	char ch;
	while (music.get(ch)) {
		str += ch;
	}
	for (int i = 0; i < 44; ++i) {
		output << str[i];
	}
	double sec = std::stod(argv[2]), percent = std::stod(argv[3]);
	int step = 44100 * sec, index = 0, size_power_2 = find_max_2_power(step), N;
	copy.resize(size_power_2);
	vec = parse(str);
	N = vec.size();
	while (N > 0) {
		for (int i = 0; i < size_power_2; ++i) {
			copy[i] = Complex(0, 0);
		}
		for (int i = 0; i < step && step * index + i < vec.size(); ++i) {
			copy[i] = vec[step * index + i];
		}
		fft(copy, false);
		equalizer(copy, percent);
		fft(copy, true);
		for (int i = 0; i < step; ++i) {	
			output << (char) copy[i]._Re;
		}
		N -= step;
		++index;
	}
	output.close();
	return 0;
}
