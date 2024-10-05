#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

unsigned solve(unsigned val) {
    vector<unsigned> digits;
    while (val != 0) {
        digits.push_back(val % 10);
        val /= 10;
    }
    auto pos = copy_if(digits.begin(), digits.end(), digits.begin(), [](unsigned val) {
        return val % 2 == 0;
    });
    return accumulate(digits.begin(), pos, 0);
}

int main(int, char const *[]) {
    unsigned val;
    while (cin >> val) {
        cout << solve(val) << endl << endl;
    }
    return 0;
}