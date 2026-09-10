#include <iostream>

void TryRead(int& number) {
    if (!(std::cin >> number)) {
        std::cout << "Fail on reading the number." << std::endl;
        std::exit(0);
    }
}

bool IsNotNegative(int number) { 
    return abs(number) == number;
}

int main() {
    int number;
    
    std::cout << "Enter the number: ";
    TryRead(number);
    
    bool std_non_negative_check = (number >= 0);
    
    if (IsNotNegative(number) == std_non_negative_check) {
        std::cout << "Try again...." << std::endl;
    } else {
        std::cout << "You broke my program :(" << std::endl;
        exit(1);
    }

    return 0;
}