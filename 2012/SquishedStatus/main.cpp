#include <iostream>
#include <vector>
using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;

static const long long MODULO = 4207849484;

long long solve(int M, string status) {
    vector<long long> dp(status.size() + 1);
    dp[0] = 1;
    for (int i = 1; i <= status.size(); i++) {
        if (i >= 1) {
            int n = status[i-1] - '0';
            if (n >= 1 && n <= M) {
                dp[i] += dp[i-1];
                dp[i] %= MODULO;
            }
        }
        if (i >= 2) {
            int n = (status[i-2] - '0') * 10 + status[i-1] - '0';
            if (status[i-2] != '0' && n >= 1 && n <= M) {
                dp[i] += dp[i-2];
                dp[i] %= MODULO;
            }
        }
        if (i >= 3) {
            int n = (status[i-3] - '0') * 100 + (status[i-2] - '0') * 10 + status[i-1] - '0';
            if (status[i-3] != '0' && n >= 1 && n <= M) {
                dp[i] += dp[i-3];
                dp[i] %= MODULO;
            }
        }
    }
    return dp[status.size()];
}

int main() {
    //long long hoge = solve(255, "12341251234123521312341234161618237413847123941853188172635418517765312376451234716235187364517365223412341234123434321341234123412341235134321123412351234213125122512512121521521521212112521121212311234125123412352131234123416161823741384712394185318817263541851776531237645123471623518736451736522341234123412343432134123412341234123513432112341235123421312512251251212152152152121211252112121231123412512341235213123412341616182374138471239418531881726354185177653123764512347162351873645173652234123412341234343213412341234123412351343211234123512342131251225125121215215215212121125211212123112341251234123521312341234161618237413847123941853188172635418517765312376451234716235187364517365223412341234123434321341234123412341235134321123412351234213125122512512121521521521212112521121212311234125123412352131234123416161823741384712394185318817263541851776531237645123471623518736451736522341234123412343432134123412341234123513432112341235123421312512251251212152152152121211252112121231");
    //dump(hoge);
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int M;
        string status;
        cin >> M >> status;
        long long ans = solve(M, status);
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
}
