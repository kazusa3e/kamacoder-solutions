#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solve(const string &a, const string &b) {
    string ret(a.size() + b.size(), '\0');
    auto pos = copy(a.begin(), a.begin() + a.size() / 2, ret.begin());
    pos = copy(b.begin(), b.end(), pos);
    copy(a.begin() + a.size() / 2, a.end(), pos);
    return ret;
}

int main(int, char const *[]) {
    unsigned n; cin >> n; getchar();
    while (n--) {
        string a, b;
        getline(cin, a); getline(cin, b);
        cout << solve(a, b) << endl;
    }
    return 0;
}