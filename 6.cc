#include <iostream>

using namespace std;

int main(int, char const *[]) {
    int N;
    while (cin >> N) {
        while (N-- != 0) {
            unsigned cnt; cin >> cnt; 
            unsigned sum = 0;
            while (cnt-- != 0) {
                int val; cin >> val; sum += val;
            }
            cout << sum << endl;
            if (N != 0) cout << endl;
        }
    }
    return 0;
}