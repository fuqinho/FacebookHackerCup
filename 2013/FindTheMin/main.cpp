#include <iostream>

const int MAX_SIZE = 1 << 17;
int size, dat[MAX_SIZE*2-1], m[100001], v[100001];

void init(int min_size) {
    size = 1;
    while (size < min_size) size *= 2;
    memset(dat, 0, sizeof(dat));
}

void add(int k, int x) {
    k += size-1;
    dat[k] += x;
    while (k > 0) {
        k = (k-1) / 2;
        dat[k] = std::min(dat[k*2+1], dat[k*2+2]);
    }
}

int find_min_unused(int k = 0) {
    if (k >= size-1) return k-(size-1);
    return (dat[k*2+1] == 0) ? find_min_unused(k*2+1) : find_min_unused(k*2+2);
}

int solve(int n, int k, int a, int b, int c, int r) {
    // 最初のk個の数列生成
    m[0] = a;
    for (int i=1; i<k; i++) m[i] = ((long long)b * m[i-1] + c) % r;

    // 最初のk個の数をsegtreeに反映させる
    init(k+1);
    for (int i=0; i<k; i++) if (m[i] <= k) add(m[i], 1);

    // segtreeから使われてない最小の数を取得して、segtree更新する処理を
    // (k+1)回繰り返す。あとはループしてるっぽいので打ち切り
    for (int i=0; i<=k; i++) {
        v[i] = find_min_unused();
        add(v[i], 1);
        if (m[i] <= k) add(m[i], -1);
    }
    return v[(n-1-k) % (k+1)];
}

int main() {
    int T; std::cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k, a, b, c, r;
        std::cin >> n >> k >> a >> b >> c >> r;
        int ans = solve(n, k, a, b, c, r);
        std::cout << "Case #" << t << ": " << ans << std::endl;
    }
}
