#include <iostream>
#include <vector>
using namespace std;

class BipartGraph {
public:
    BipartGraph(int n) {
        G = vector<vector<int> >(n);
        match = vector<int>(n);
        used = vector<bool>(n);
    }
    void AddEdge(int u, int v) {
        G[u].push_back(v); G[v].push_back(u);
    }
    int MaxMatch() {
        fill(match.begin(), match.end(), -1);
        int res = 0;
        for (int i=0; i<G.size(); i++) if (match[i] < 0) {
            fill(used.begin(), used.end(), false);
            if (dfs(i)) res++;
        }
        return res;
    }
private:
    vector<vector<int> > G;
    vector<int> match;
    vector<bool> used;
    bool dfs(int v) {
        used[v] = true;
        for (int i=0; i<G[v].size(); i++) {
            int u = G[v][i];
            if (match[u] < 0 || (!used[match[u]] && dfs(match[u]))) {
                match[v] = u; match[u] = v;
                return true;
            }
        }
        return false;
    }
};

bool ok(int m, string k1, string k2) {
    BipartGraph G(m*2);
    int l = k1.size() / m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            bool match = true;
            for (int k = 0; k < l; k++) {
                if (k1[i*l+k] != '?' && k2[j*l+k] != '?' && k1[i*l+k] != k2[j*l+k]) {
                    match = false;
                    break;
                }
            }
            if (match) G.AddEdge(i, m+j);
        }
    }
    return G.MaxMatch() == m;
}

string solve(int m, string k1, string k2) {
    if (!ok(m, k1, k2)) return "IMPOSSIBLE";
    for (int i = 0; i < k1.size(); i++) {
        if (k1[i] == '?') {
            for (int c = 'a'; c <= 'f'; c++) {
                k1[i] = c;
                if (ok(m, k1, k2)) break;
            }
        }
    }
    return k1;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int m;
        string k1, k2;
        cin >> m >> k1 >> k2;
        string ans = solve(m, k1, k2);
        cout << "Case #" << t << ": " << ans << endl;
    }
}
