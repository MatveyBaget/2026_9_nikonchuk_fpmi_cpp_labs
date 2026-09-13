#include <iostream>


int main() {

    int num;
    std::cout << "Enter number:\n";
    
    if (!(std::cin >> num)) {
       std::cout << "you must input an integer number!\n";
       std::exit(-1);
    }

    // until correct input - bad!
    // while (!(std::cin >> num)) {
    //     std::cout << "you must input an integer number! try again!\n";
    //     std::cin.clear();
    //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    // }

    int digit_sum = 0;
    int curr_digit;
    // 12345
    // 5->1234->4->123->3->12->2->1->0

    while (num > 0) {
        //curr_digit = num % 10;
        //digit_sum += curr_digit;
        digit_sum += num % 10;
        num /= 10;
    }

    std::cout << "Sum of digits: " << digit_sum;

    return 0;
}
