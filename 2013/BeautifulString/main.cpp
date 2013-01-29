#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int idx(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a';
    return -1;
}

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    int N; ss >> N;
    for (int t = 1; t <= N; t++) {
        string s; getline(cin, s);
        vector<int> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            if (idx(s[i]) != -1) cnt[idx(s[i])]++;
        }
        sort(cnt.rbegin(), cnt.rend());
        int ans = 0;
        for (int i = 0; i < cnt.size(); i++) {
            ans += (26-i) * cnt[i];
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}
