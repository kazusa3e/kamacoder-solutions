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
    vector<vector<unsigned>> dp(num_items, vector<unsigned>(caps + 1, 0));
    for (unsigned i = 0; i != num_items; ++i) dp[i][0] = 0;
    for (unsigned j = 0; j <= caps; ++j) dp[0][j] = (j >= weights[0]) ? values[0] : 0;

    for (unsigned i = 1; i != num_items; ++i) {
        for (unsigned j = 1; j <= caps; ++j) {
            if (j < weights[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(
                dp[i - 1][j],
                dp[i - 1][j - weights[i]] + values[i]
            );
        }
    }
    cout << dp.back().back() << endl;
}


int main(int, char const *[]) {
    handle_input();
    solve();
    return 0;
}