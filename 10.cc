#include <iostream>

using namespace std;

unsigned solve(unsigned m, unsigned k) {
    unsigned cnt = 0;
    while (m >= k) {
        unsigned reward = m / k;
        m -= reward * k;
        cnt += reward * k;
        m += reward;
    }
    cnt += m;
    return cnt;
}

int main(int, char const *[]) {
    unsigned M, K;
    while (cin >> M >> K) {
        if (M == 0 && K == 0) break;
        cout << solve(M, K) << endl;
    }
    return 0;
}