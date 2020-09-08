#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <boost/rational.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#define drob(a, b) rational<cpp_int>(a, b)

using namespace std;
using boost::rational;
using boost::multiprecision::cpp_int;


inline cpp_int fac(int n) {
    static vector<cpp_int> cash(100000, 0); 
    if (n == 0) return 1;
    if (cash[n]) { return cash[n]; }
    return (cash[n] = n * fac(n - 1));
}

rational<cpp_int> C(int n, int k) {
    return drob(fac(n),fac(k)*fac(n-k));
}

rational<cpp_int> A(int n, int k) {
    return drob(fac(n),fac(n-k));
}

int main() {
    auto v = C(52, 5);
    cout << v << endl;
}
