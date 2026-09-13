#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>


int main() {

    double x = 1.0;
    int k = 20;
    double eps = std::pow(10, -k);

    double res = 0.0; // f(x)
    double a_n = 1.0;
    int n = 1;

    while(std::fabs(a_n) >= eps/*|a_n| >= eps*/) {
        res += a_n; // f(x) += a_n
        a_n *= x;
        a_n /= n;
        ++n;
    }
    
    std::cout << std::setprecision(k);
    std::cout << "my exp: " << res << '\n';
    std::cout << "stdexp: " << std::exp(x) << '\n';

/*
    double a = 0.1; // 0.100000000000003
    double b = 0.2; // 0.200000000000008

    double sum = a + b; // 0.300000000001
    assert(std::fabs(sum -  0.3) < 1e-10);
*/
    return 0;
}
