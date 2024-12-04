#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n, m;

int main(int, char const *[]) {
    std::cin >> n >> m;
    std::vector<int> dp(max(n + 1, 1), 0); dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = accumulate(dp.begin() + max(0, i - m), dp.begin() + i, 0);
    }
    cout << dp[n] << endl;
    return 0;
}