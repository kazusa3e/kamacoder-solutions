#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned caps;
vector<unsigned> weights;
vector<unsigned> values;

void handle_input() {
    unsigned n; cin >> n >> caps;
    for (unsigned ix = 0; ix != n; ++ix) {
        unsigned w, v; cin >> w >> v;
        weights.push_back(w); values.push_back(v);
    }
}

void solve() {
    // [caps] => ans
    vector<unsigned> dp(caps + 1, 0);
    
    for (unsigned i = 0; i != weights.size(); ++i) {
        for (int j = weights[i]; j < caps + 1; ++j) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    cout << dp.back() << endl;
}

int main(int, char const *[]) {
    handle_input();
    solve();
    return 0;
}