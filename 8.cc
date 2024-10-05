#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

unsigned solve(const vector<unsigned> &vec) {
    const unsigned sum = accumulate(vec.begin(), vec.end(), 0);
    const unsigned avg = sum / vec.size();

    unsigned cnt = 0;
    auto pos = find_if(vec.begin(), vec.end(), [&avg](unsigned val) { return val > avg; });
    while (pos != vec.end()) {
        cnt += *pos - avg;
        pos = find_if(pos + 1, vec.end(), [&avg](unsigned val) { return val > avg; });
    }
    return cnt;
}

int main(int, char const *[]) {
    int N;
    while (cin >> N) {
        if (N == 0) break;
        vector<unsigned> blocks;
        while (N-- != 0) {
            unsigned val; cin >> val; blocks.push_back(val);
        }
        cout << solve(blocks) << endl << endl;
    }
    return 0;
}