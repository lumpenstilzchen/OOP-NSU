#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>


int binary(int a, int b) {
    if (b % 2 != 0) {
        return a - b;
    }
    else {
        return a + b;
    }
}


int main() {
    // Parsing

    std::ifstream file1("s04_v1_42_1.txt");

    std::vector<int> numbers1;
    int number1;

    while (file1 >> number1) {
        numbers1.push_back(number1);
        file1.ignore();
    }

    std::ifstream file2("s04_v1_42_2.txt");

    std::vector<int> numbers2;
    int number2;

    while (file2 >> number2) {
        numbers2.push_back(number2);
        file2.ignore();
    }
	
	// Binary operation

    int binary_op1 = std::accumulate(numbers1.begin(), numbers1.end(), 0, binary);
    std::cout << "Binary result for Bigger Vector = " << binary_op1 << '\n';

    int binary_op2 = std::accumulate(numbers2.begin(), numbers2.end(), 0, binary);
    std::cout << "Binary result for Smaller Vector = " << binary_op2 << '\n';

    std::cout << '\n';
    
    // Numbers with frequency >=3 / >=2

    std::map<int, int> table1;
    std::map<int, int> table2;

    for (int num : numbers1) {
        table1[num]++;
    }

    for (int num : numbers2) {
        table2[num]++;
    }

    for (std::map<int, int>::iterator iter = table1.begin(); iter != table1.end(); ) {
        if (iter->second < 3) {
            iter = table1.erase(iter);
        }
        else {
            ++iter;
        }
    }

    for (std::map<int, int>::iterator iter = table2.begin(); iter != table2.end(); ) {
        if (iter->second < 2) {
            iter = table2.erase(iter);
        }
        else {
            ++iter;
        }
    }

    std::cout << "BIGGER VECTOR" << '\n';
    for (std::pair<int, int> element : table1) {
        std::cout << "Number " << element.first << ": frequency " << element.second << '\n';
    }

    std::cout << "SMALLER VECTOR" << '\n';
    for (std::pair<int, int> element : table2) {
        std::cout << "Number " << element.first << ": frequency " << element.second << '\n';
    }

    // Intersection search

    std::cout << '\n';

    for (std::map<int, int>::iterator iter2 = table2.begin(); iter2 != table2.end(); ++iter2) {
        for (std::map<int, int>::iterator iter1 = table1.begin(); iter1 != table1.end(); ++iter1) {
            if (iter2->first == iter1->first) {
                std::cout << "Number " << iter2->first << "; frequency in Bigger Vector: " << iter1->second << "; frequency in Smaller Vector: " << iter2->second << '\n';
            }
        }
    }

    std::cout << '\n';

    std::for_each(table2.begin(), table2.end(), [&table1](std::pair<int, int> num) {
        std::map<int, int>::iterator iter = table1.find(num.first);
        if (iter != table1.end()) {
            std::cout << "Number " << num.first << "; frequency in Bigger Vector: " << iter->second << "; frequency in Smaller Vector: " << num.second << '\n';
        }
    });

	return 0;
}
