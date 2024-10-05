#include <iostream>

using namespace std;

int main(int, char const *[]) {
    int N;
    while (cin >> N) {
        if (N == 0) break;
        unsigned sum = 0;
        while (N-- != 0) {
            int val; cin >> val; sum += val;
        }
        cout << sum << endl;
    }
    return 0;
}