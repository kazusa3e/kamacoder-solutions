#include <iostream>
#include <vector>

using namespace std;

int main(int, char const *[]) {
    int N;
    while (cin >> N) {
        vector<unsigned> vec(21, 0);
        while (N-- != 0) {
            int a, b; cin >> a >> b;
            vec[a] = b;
        }
        auto depth = [&](unsigned ix) -> unsigned {
             unsigned cnt = 0;
             while (vec[ix] != 0) {
                ix = vec[ix]; cnt += 1;
             }
             return cnt;
        };
        unsigned d1 = depth(1), d2 = depth(2);
        if (d1 == d2) {
            cout << "You are my brother" << endl;
        } else if (d1 > d2) {
            cout << "You are my elder" << endl;
        } else {
            cout << "You are my younger" << endl;
        }
    }
    return 0;
}