#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;

void handle_input() {
    int n, m; cin >> n >> m;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));
    for (unsigned i = 0; i != n; ++i) {
        for (unsigned j = 0; j != m; ++j) {
            cin >> grid[i][j];
        }
    }
}

constexpr int directions[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
};

vector<pair<int, int>> bfs(int x, int y) {
    vector<pair<int, int>> ret;
    ret.push_back({x, y});
    visited[x][y] = true;
    queue<pair<int, int>> qu; qu.push({x, y});
    bool flag = true;
    if (x == 0 || x == grid.size() - 1 || y == 0 || y == grid[0].size() - 1) flag = false;
    while (!qu.empty()) {
        auto curr = qu.front(); qu.pop();
        for (const auto &d : directions) {
            int i = curr.first + d[0], j = curr.second + d[1];
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) continue;
            if (visited[i][j]) continue;
            if (grid[i][j] == 0) continue;
            if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) flag = false;
            visited[i][j] = true; qu.push({i, j}); ret.push_back({i, j});
        }
    }
    if (!flag) ret.resize(0);
    return ret;
}

void print() {
    for (unsigned i = 0; i != grid.size(); ++i) {
        for (unsigned j = 0; j != grid[0].size(); ++j) {
            cout << grid[i][j];
            if (j + 1 != grid[0].size()) cout << " ";
        }
        cout << endl;
    }
}

int main(int, char const *[]) {
    handle_input();
    
    for (unsigned i = 0; i != grid.size(); ++i) {
        for (unsigned j = 0; j != grid[0].size(); ++j) {
            if (visited[i][j]) continue;
            if (grid[i][j] == 0) continue;
            auto ans = bfs(i, j);
            for (const auto &p : ans) {
                grid[p.first][p.second] = 0;
            }
        }
    }
    print();
    return 0;
}