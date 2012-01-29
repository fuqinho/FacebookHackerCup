#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

static const int MAX_N = 10000000;

int solve(const vector<int>& min_t, int S) {
    int res = -1;
    for (int i = 1; i * i <= S; i++) {
        if (S % i == 0) {
            int a = i;
            int b = S / i;
            int t = min_t[a] + min_t[b];
            if (res == -1 || res > t) res = t;
        }
    }
    return res;
}

int main() {
    vector<int> dp(MAX_N, 0);
    dp[0] = 1;
    vector<int> min_t(MAX_N + 1, -1);
    min_t[0] = 1;
    for (int i = 0; i < MAX_N; i++ ){
        for (int j = 1; j < MAX_N; j++) {
            if (dp[j] + dp[j-1] > MAX_N) break;
            dp[j] += dp[j-1];
            int t = i + j;
            if (min_t[dp[j]] == -1 || t < min_t[dp[j]]) min_t[dp[j]] = t;
        }
    }

    int R; cin >> R;
    for (int i = 0; i < R; i++) {
        int S; cin >> S;
        cout << "Case #" << i+1 << ": " << solve(min_t, S) << endl;
    }
}
