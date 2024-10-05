#include <iostream>

using namespace std;

void print(unsigned n) {
    for (unsigned row = 0; row != n; ++row) {
        cout << string(n - 1 - row, ' ');
        for (unsigned ix = 0; ix != row; ++ix) { cout << ix + 1; }
        cout << row + 1;
        for (unsigned ix = row; ix > 0; --ix) { cout << ix; }
        cout << endl;
    }
    for (unsigned row = n - 1; row > 0; --row) {
        cout << string(n - row, ' ');
        for (unsigned ix = 1; ix != row; ++ix) { cout << ix; }
        cout << row;
        for (unsigned ix = row - 1; ix > 0; --ix) { cout << ix; }
        cout << endl;
    }
}

int main(int, char const *[]) {
    int n;
    while (cin >> n) print(n);
    return 0;
}