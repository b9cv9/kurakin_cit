#include <iostream>
using namespace std;

int fib(long long  n) {
    if (n == 1 || n == 0) return 0;
    if (n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}
int main() {
    int n;
    cout << "Введите n: "; cin >> n;
    cout << fib(n) << endl;
    return 0;
}

