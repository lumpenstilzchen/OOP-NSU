#include <random>

template <typename in, typename out>
out add_ext_mod(const in& a, const in& b) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist1(0, 1);
	std::uniform_int_distribution<> dist2(1, 100);

	out sum = 0;

	if (dist1(gen) == 1) {
		sum = a + b + dist2(gen);
	}
	else {
		sum = a + b;
	}

	return sum;
}
