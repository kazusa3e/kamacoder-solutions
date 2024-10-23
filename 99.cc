#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int directions[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
};

vector<vector<int>> g;
vector<vector<bool>> visited;

void handle_input() {
    int n, m; cin >> n >> m;
    g.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));
    for (unsigned i = 0; i != n; ++i) {
        for (unsigned j = 0; j != m; ++j) {
            cin >> g[i][j];
        }
    }
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (const auto &d: directions) {
        int new_x = x + d[0], new_y = y + d[1];
        if (new_x < 0 || new_x >= g.size() || new_y < 0 || new_y >= g[0].size()) continue;
        if (!visited[new_x][new_y] && g[new_x][new_y] == 1) {
            dfs(new_x, new_y);
        }
    }
}

void bfs(int x, int y) {
    queue<pair<int, int>> qu; qu.push(make_pair(x, y)); visited[x][y] = true;
    while (!qu.empty()) {
        auto curr = qu.front(); qu.pop();
        visited[curr.first][curr.second] = true;
        for (const auto &d : directions) {
            int new_x = curr.first + d[0], new_y = curr.second + d[1];
            if (new_x < 0 || new_x >= g.size() || new_y < 0 || new_y >= g[0].size()) continue;
            if (visited[new_x][new_y]) continue;
            if (g[new_x][new_y] == 0) continue;
            qu.push(make_pair(new_x, new_y)); visited[new_x][new_y] = true;
        }
    }
}

int main(int, char const *[]) {
    handle_input();
    unsigned ans = 0;
    for (unsigned i = 0; i != g.size(); ++i) {
        for (unsigned j = 0; j != g[0].size(); ++j) {
            if (visited[i][j]) continue;
            if (g[i][j] == 0) continue;
            ans += 1;
            // dfs(i, j);
            bfs(i, j);
        }
    }
    cout << ans << endl;
    return 0;
}