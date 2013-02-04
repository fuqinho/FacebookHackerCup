#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
int C[10001][10001];

int solve(int N, int K, vector<int>& a) {
    sort(a.rbegin(), a.rend());
    long long res = 0;
    for (int i = 0; i < N; i++) {
        if (N-1-i >= K-1)
            res = (res + (long long)a[i] * C[N-1-i][K-1]) % MOD;
    }
    return res;
}

int main() {
    int T; cin >> T;
    memset(C, 0, sizeof(0));
    C[0][0] = 1;
    for (int i = 1; i <= 10000; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
    for (int t = 1; t <= T; t++) {
        int N, K; cin >> N >> K;
        vector<int> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];
        int ans = solve(N, K, a);
        cout << "Case #" << t << ": " << ans << endl;
    }
}
