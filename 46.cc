#include <iostream>
#include <vector>

using namespace std;

unsigned num_items, caps;
vector<unsigned> weights, values;

void handle_input() {
     cin >> num_items >> caps;
     for (unsigned ix = 0; ix != num_items; ++ix) {
        unsigned val; cin >> val; weights.push_back(val);
     }
     for (unsigned ix = 0; ix != num_items; ++ix) {
        unsigned val; cin >> val; values.push_back(val);
     }
}

void solve() {
    vector<unsigned> dp(caps + 1, 0);
    for (unsigned j = 0; j <= caps; ++j) dp[j] = (j >= weights[0]) ? values[0] : 0;
    for (unsigned i = 1; i != num_items; ++i) {
        for (unsigned j = caps; j >= 1; --j) {
            if (j < weights[i]) continue;
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