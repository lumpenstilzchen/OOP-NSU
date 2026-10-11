#include <iostream>
#include <random>
#include "my_lib.h"

namespace simple {
	int add(int a, int b) {
		return a + b;
	}
}

namespace modded {
	int add(int a, int b) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist1(0, 1);
		std::uniform_int_distribution<int> dist2(1, 100);

		int sum = 0;

		if (dist1(gen) == 1) {
			sum = a + b + dist2(gen);
		}

		else {
			sum = a + b;
		}

		return sum;
	}
}
