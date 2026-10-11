#include <iostream>
#include "my_lib/my_lib.h"

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << "Simple add = " << simple::add(x, y) << std::endl;
    std::cout << "Modded add = " << modded::add(x, y) << std::endl;
    return 0;
}
