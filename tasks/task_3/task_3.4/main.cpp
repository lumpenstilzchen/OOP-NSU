#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include "add_ext_mod.h"

int main() {
	int N = 200;
	int M = 10;


	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(-N, N);

	std::array<double, 10> arr;
	std::vector<double> vect;
	std::list<double> lst;
	std::deque<double> dq;

	for (int i = 0; i < M; i++) {
		arr[i] = dist(gen);
		vect.push_back(dist(gen));
		lst.push_back(dist(gen));
		dq.push_back(dist(gen));
	}

	// Operations with containers

	int random_num = dist(gen);

	std::array<int, 10> arr2;
	std::vector<int> vect2;
	std::list<int> lst2;
	std::deque<int> dq2;

	for (int i = 0; i < M; i++) {
		vect2.push_back(add_ext_mod<double, int>(arr[i], random_num));
	}

	for (std::vector<double>::iterator iter = vect.begin(); iter != vect.end(); ++iter) {
		lst2.push_back(add_ext_mod<double, int>(*iter, random_num));
	}

	for (double element : lst) {
		dq2.push_back(add_ext_mod<double, int>(element, random_num));
	}
	
	int j = 0;
	for (std::deque<double>::iterator iter = dq.begin(); iter != dq.end(); ++iter, j++) {
		arr2[j] = add_ext_mod<double, int>(*iter, random_num);
	}
	
	// Creating markdown table

	std::ofstream out;
	out.open("table.md");

	if (out.is_open()) {
		out << "| no. | arr | vect | lst | dq | arr2 | vect2 | lst2 | dq2 |\n";
		out << "|-----|-----|------|-----|----|------|-------|------|-----|\n";
		
		std::list<double>::iterator iter_lst = lst.begin();
		std::list<int>::iterator iter_lst2 = lst2.begin();


		for (int i = 0; i < M; i++) {
			out << "| " << i + 1
				<< " | " << arr[i]
				<< " | " << vect[i]
				<< " | " << *iter_lst
				<< " | " << dq[i]
				<< " | " << arr2[i]
				<< " | " << vect2[i]
				<< " | " << *iter_lst2
				<< " | " << dq2[i]
				<< " |\n";

			++iter_lst;
			++iter_lst2;
		}

		out.close();
	}

	return 0;
}
