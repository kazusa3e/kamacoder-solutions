#include <iostream>
#include <string>

using namespace std;

void solve(string &s) {
    for (auto ix = 0; ix < s.size(); ix += 2) {
        swap(s[ix], s[ix + 1]);
    }
}

int main(int, char const *[]) {
    int n; cin >> n; getchar();
    while (n--) {
        string s; getline(cin, s);
        solve(s);
        cout << s << endl;
        
    }
    return 0;
}