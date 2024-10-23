#include <iostream>
#include <vector>
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

unsigned m_total {0};
unsigned m_curr {0};
constexpr int directions[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
};

bool bfs(int x, int y) {
    queue<pair<int, int>> qu; qu.push({x, y});
    visited[x][y] = true;
    bool flag = true;
    if (x == 0 || x == grid.size() - 1|| y == 0 || y== grid[0].size() - 1) flag = false;
    while (!qu.empty()) {
        auto curr = qu.front(); qu.pop();
        m_curr += 1;
        for (const auto &d : directions) {
            int i = curr.first + d[0], j = curr.second + d[1];
            if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) continue;
            if (visited[i][j]) continue;
            if (grid[i][j] == 0) continue;
            visited[i][j] = true;
            if (i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) flag = false;
            qu.push({i, j});
        }
    }
    return flag;
}

int main(int, char const *[]) {
    handle_input();
    for (unsigned i = 0; i != grid.size(); ++i) {
        for (unsigned j = 0; j != grid[0].size(); ++j) {
            if (visited[i][j]) continue;
            if (grid[i][j] == 0) continue;
            m_curr = 0;
            if (bfs(i, j)) {
                m_total += m_curr;
            }
        }
    }
    cout << m_total << endl;
    return 0;
}