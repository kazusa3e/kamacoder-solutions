#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;

vector<vector<int>> paths;
vector<int> path;

void handle_input() {
    int n, m; cin >> n >> m;
    graph.resize(n + 1, vector<int>(n + 1, 0));
    while (m--) {
        int f, t; cin >> f >> t;
        graph[f][t] = 1;
    }
}

void dfs(const int origin, const int dest) {
    if (origin == dest) {
        paths.push_back(path); return;
    }
    for (int j = 1; j != graph.size(); ++j) {
        if (graph[origin][j] == 0) continue;
        path.push_back(j);
        dfs(j, dest);
        path.pop_back();
    }
}

template <typename Iter>
ostringstream join(Iter b, Iter e, const string &delim) {
    ostringstream oss;
    for (; b + 1 != e; ++b) {
        oss << *b << delim;
    }
    oss << *b;
    return oss;
}

int main(int, char const *[]) {
    handle_input();
    path.push_back(1);
    dfs(1, graph.size() - 1);
    if (paths.empty()) {
        cout << -1 << endl;
    } else {
        for_each(paths.begin(), paths.end(), [](const auto &p) {
            cout << join(p.begin(), p.end(), " ").str() << endl;
        });
    }
    return 0;
}
