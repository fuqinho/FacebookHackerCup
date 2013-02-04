#include <iostream>
#include <cstring>
using namespace std;

bool ng[40000][40000];
bool ok[40000][40000];

long long solve(int W, int H, int P, int Q, int N, int X, int Y, long long a, long long b, long long c, long long d) {
    memset(ng, 0, sizeof(ng));
    memset(ok, 0, sizeof(ok));
    int x = X, y = Y;
    for (int i=0; i<N; i++) {
        ng[y][x] = true;
        int nx = (x * a + y * b + 1) % W;
        int ny = (x * c + y * d + 1) % H;
        x = nx; y = ny;
    }
    for (int c=0; c<W; c++) {
        int ac = 0;
        for (int r=0; r<H; r++) {
            ac = ng[r][c] ? 0 : ac+1;
            if (ac >= Q) ok[r][c] = true;
        }
    }
    long long res = 0;
    for (int r=0; r<H; r++) {
        int ac = 0;
        for (int c=0; c<W; c++) {
            ac = ok[r][c] ? ac+1 : 0;
            if (ac >= P) res++;
        }
    }
    return res;
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int W, H, P, Q, N, X, Y, a, b, c, d;
        cin >> W >> H >> P >> Q >> N >> X >> Y >> a >> b >> c >> d;
        long long ans = solve(W, H, P, Q, N, X, Y, a, b, c, d);
        cout << "Case #" << t << ": " << ans << endl;
    }
}
