#include <iostream>
#include <vector>
using namespace std;

int solve(string line) {
    vector<int> counts(27);
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') continue;
        counts[line[i] - 'A']++;
    }
    int result = min(counts['H'-'A'], counts['A'-'A']);
    result = min(result, counts['K'-'A']);
    result = min(result, counts['E'-'A']);
    result = min(result, counts['R'-'A']);
    result = min(result, counts['U'-'A']);
    result = min(result, counts['P'-'A']);
    result = min(result, counts['C'-'A'] / 2);

    return result;
}

int main() {
    int T; cin >> T;
    string line;
    getline(cin, line);
    for (int i = 0; i < T; i++) {
        getline(cin, line);
        int answer = solve(line);
        cout << "Case #" << i+1 << ": " << answer << endl;
    }
}
