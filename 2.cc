#include <iostream>

using namespace std;

int main(int, char const *[]) {
    int N;
    while (cin >> N) {
        while (N-- != 0) {
            int a, b;
            cin >> a >> b;
            cout << a + b << endl;
        }
    }
    return 0;
}