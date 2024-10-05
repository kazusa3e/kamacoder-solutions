#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool solve(const vector<unsigned> &vec) {
    stack<unsigned> st;
    auto iter = vec.begin();
    for (unsigned ix = 1; ix <= vec.size(); ++ix) {
        st.push(ix);
        while (!st.empty() && st.top() == *iter) {
            st.pop(); ++iter;
        }
    }
    return iter == vec.end();
}

int main(int, char const *[]) {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<unsigned> vec;
        while (n--) {
            int val; cin >> val; vec.push_back(val);
        }
        auto ans = solve(vec);
        if (ans) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}