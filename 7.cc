#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main(int, char const *[]) {
    string line;
    while (getline(cin, line)) {
        unsigned scores = 0, cnt = 0;
        bool valid = true;
        for (auto ch : line) {
            if (ch == 'A') {
                scores += 4; cnt += 1;
            } else if (ch == 'B') {
                scores += 3; cnt += 1;
            } else if (ch == 'C') {
                scores += 2; cnt += 1;
            } else if (ch == 'D') {
                scores += 1; cnt += 1;
            } else if (ch == 'F') {
                scores += 0; cnt += 1;
            } else if (ch != ' ') {
                valid = false; break;
            }
        }
        if (valid) {
            cout << fixed << setprecision(2) << (double) scores / cnt << endl;
        } else {
            cout << "Unknown" << endl;
        }
    }
    return 0;
}