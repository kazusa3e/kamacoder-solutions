#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

using point = pair<int, int>;

constexpr int directions[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int n, m;
vector<vector<int>> grid;
vector<vector<bool>> visited1, visited2;
set<point> g1, g2;

void handle_input() {
    cin >> n >> m;
    grid.resize(n, vector<int>(m, 0));
    for (unsigned i = 0; i != n; ++i) {
        for (unsigned j = 0; j != m; ++j) {
            cin >> grid[i][j];
        }
    }
    visited1.resize(n, vector<bool>(m, false));
    visited2.resize(n, vector<bool>(m, false));
}

void dfs(point p, vector<vector<bool>> &visited, set<point> &s) {
    if (visited[p.first][p.second]) return;
    s.insert(p); visited[p.first][p.second] = true;
    for (const auto &d : directions) {
        int new_x = p.first + d[0], new_y = p.second + d[1];
        if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) continue;
        if (grid[new_x][new_y] < grid[p.first][p.second]) continue;
        dfs({new_x, new_y}, visited, s);
    }
}

void solve() {
    // group 1
    for (unsigned i = 0; i != n; ++i) { dfs({i, 0}, visited1, g1); }
    for (unsigned j = 0; j != m; ++j) { dfs({0, j}, visited1, g1); }

    // group 2
    for (unsigned i = 0; i != n; ++i) { dfs({i, m - 1}, visited2, g2); }
    for (unsigned j = 0; j != m; ++j) { dfs({n - 1, j}, visited2, g2); }

    vector<point> inter;
    set_intersection(g1.begin(), g1.end(), g2.begin(), g2.end(), back_inserter(inter));
    for (const auto &p : inter) {
        cout << p.first << " " << p.second << endl;
    }
}

int main(int, char const *[]) {
    handle_input();
    solve();

    return 0;
}