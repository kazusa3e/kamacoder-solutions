#include <iostream>
#include <string>

using namespace std;

string solve(const string &s) {
    bool flag = true;
    string ret;
    for (auto ch : s) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (flag) {
                ret += toupper(ch); flag = false;
            }
        } else {
            flag = true;
        }
    }
    return ret;
}

int main(int, char const *[]) {
    int n;
    cin >> n;
    getchar();
    while (n-- != 0) {
        string line;
        getline(cin, line);
        cout << solve(line) << endl;
    }
    return 0;
}