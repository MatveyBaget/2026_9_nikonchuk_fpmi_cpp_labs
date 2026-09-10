#include <iostream>



int main() {
    
    int num;
    std::cout << "enter integer number\n";
    
    if (!(std::cin >> num)) {
        std::cout << "error: invalid input\n";
        std::exit(-1);
    }

    int digit_sum = 0;

    while (num > 0) {
        int curr_digit = num % 10;
        digit_sum += curr_digit;
        num /= 10;
    }

    std::cout << digit_sum;

    return 0;
}
