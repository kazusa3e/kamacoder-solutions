#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> grid;
vector<vector<bool>> visited;

void handle_input() {
    int n, m; cin >> n >> m;
    grid.resize(n, vector<int>(m));
    for (unsigned i = 0; i != n; ++i) {
        for (unsigned j = 0; j != m; ++j) {
            cin >> grid[i][j];
        }
    }
    visited.resize(n, vector<bool>(m, false));
}

unsigned m_max = 0;
unsigned m_curr = 0;

int directions[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
};

void dfs(int i, int j) {
    visited[i][j] = true;
    m_curr += 1;
    for (const auto &d : directions) {
        int new_x = i + d[0], new_y = j + d[1];
        if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size()) continue;
        if (visited[new_x][new_y]) continue;
        if (grid[new_x][new_y] == 0) continue;
        dfs(new_x, new_y);
    }
}

void bfs(int i, int j) {
    visited[i][j] = true;
    queue<pair<int, int>> qu; qu.push(make_pair(i, j));
    while (!qu.empty()) {
        auto curr = qu.front(); qu.pop();
        m_curr += 1;
        for (const auto &d : directions) {
            int new_x = curr.first + d[0], new_y = curr.second + d[1];
            if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size()) continue;
            if (visited[new_x][new_y]) continue;
            if (grid[new_x][new_y] == 0) continue;
            visited[new_x][new_y] = true;
            qu.push(make_pair(new_x, new_y));
        }
    }
}

int main(int, char const *[]) {
    handle_input();
    for (unsigned i = 0; i != grid.size(); ++i) {
        for (unsigned j = 0; j != grid[0].size(); ++j) {
            if (visited[i][j]) continue;
            if (grid[i][j] == 0) continue;
            m_curr = 0;
            // dfs(i, j);
            bfs(i, j);
            m_max = max(m_max, m_curr);
        }
    }

    cout << m_max << endl;
    return 0;
}