#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

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

    // Counting numbers

    int count1 = 0;
    for (std::vector<int>::iterator iter = numbers1.begin(); iter != numbers1.end(); ++iter) {
        count1++;
    }

    int count2 = 0;
    for (std::vector<int>::iterator iter = numbers2.begin(); iter != numbers2.end(); ++iter) {
        count2++;
    }

    std::cout << count1 << '\n' << count2 << '\n';
    
    std::cout << '\n';

    // Сalculation for each number
    
    std::map<int, int> table1;
    std::map<int, int> table2;

    for (int num : numbers1) {
        table1[num]++;
    }

    for (int num : numbers2) {
        table2[num]++;
    }

    std::cout << "BIGGER VECTOR" << '\n';
    for (std::pair<int, int> element : table1) {
        std::cout << "Number " << element.first << ": frequency " << element.second << '\n';
    }

    std::cout << '\n';

    std::cout << "SMALLER VECTOR" << '\n';
    for (std::pair<int, int> element : table2) {
        std::cout << "Number " << element.first << ": frequency " << element.second << '\n';
    }

    std::cout << '\n';

    // Сalculation for each number (<algorithm>)

    std::vector<int> visited1;

    std::cout << "BIGGER VECTOR" << '\n';

    for (int num : numbers1) {
        if (std::find(visited1.begin(), visited1.end(), num) == visited1.end()) {
            int count1 = std::count(numbers1.begin(), numbers1.end(), num);
            std::cout << "Number " << num << ": frequency " << count1 << '\n';
            visited1.push_back(num);
        }
    }

    std::cout << '\n';

    std::vector<int> visited2;

    std::cout << "SMALLER VECTOR" << '\n';

    for (int num : numbers2) {
        if (std::find(visited2.begin(), visited2.end(), num) == visited2.end()) {
            int count2 = std::count(numbers2.begin(), numbers2.end(), num);
            std::cout << "Number " << num << ": frequency " << count2 << '\n';
            visited2.push_back(num);
        }
    }

    std::cout << '\n';

    // Сalculation of the sum
    int sum1 = 0;
    std::for_each(numbers1.begin(), numbers1.end(), [&sum1](int num) {sum1 += num;});
    std::cout << "Sum of Bigger Vector = " << sum1 << '\n';

    int sum2;  
    sum2 = std::accumulate(numbers2.begin(), numbers2.end(), 0);
    std::cout << "Sum of Smaller Vector = " << sum2 << '\n';

    std::cout << '\n';

    // Сalculation of the sum (first 10 numbers) 

    int first_ten_sum1;
    first_ten_sum1 = std::accumulate(numbers1.begin(), numbers1.begin() + 10, 0);
    std::cout << "First 10 of Bigger Vector = " << first_ten_sum1 << '\n';

    int first_ten_sum2;
    first_ten_sum2 = std::accumulate(numbers2.begin(), numbers2.begin() + 10, 0);
    std::cout << "First 10 of Smaller Vector = " << first_ten_sum2 << '\n';


	return 0;
}

