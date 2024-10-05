#include <iostream>
#include <string>

using namespace std;

void print(char x, unsigned n) {
    if (n == 0) return;
    if (n == 1) {
        cout << x << endl; return;
    }
    cout << string(n - 1, ' ') << x << endl;
    for (unsigned row = 1; row != n - 1; ++row) {
        cout << string(n - row - 1, ' ');
        cout << x;
        if (row == 0 || row == 1) cout << string(row, ' ');
        else cout << string(2 * row - 1, ' ');
        cout << x;
        cout << endl;
    }
    cout << string(n * 2 - 1, x) << endl;
}

int main(int, char const *[]) {
    char x;
    while (cin >> x) {
        if (x == '@') break;
        unsigned n; cin >> n;
        print(x, n);
        cout << endl;
    }
    return 0;
}