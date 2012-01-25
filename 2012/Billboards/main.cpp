#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

bool check(int W, int H, const vector<string>& words, int size) {
    //cerr << "=== trying size: " << size << endl;
    int x = 0;
    int lines = 1;
    int max_lines = H / size;
    for (int i = 0; i < words.size(); i++) {
        int width = words[i].size() * size;
        if (width > W) return false;
        int width_with_space = width + size;
        if ((x == 0 && width <= W) || (x != 0 && x + width_with_space <= W)) {
            //if (x == 0) cerr << words[i];
            //else cerr << " " << words[i];
            x += (x == 0 ? width : width_with_space);
        } else {
            lines++;
            //cerr << endl;
            x = 0;
            x += width;
            //cerr << words[i];
        }
        if (lines > max_lines) return false;
    }
    //cerr << endl;
    return true;
}

int solve(int W, int H, const vector<string>& words) {    
    int chars = 0;
    for (int i = 0; i < words.size(); i++)
        chars += words[i].size();
    int size = static_cast<int>(ceil(sqrt(W * H / chars)));
    while (size > 0) {
        bool isOK = check(W, H, words, size);
        if (isOK) {
            break;
        } else {
            size--;
        }
    }
    return size;
}

int main() {
    int T; cin >> T;
    string line;
    getline(cin, line);
    for (int i = 0; i < T; i++) {
        // process input
        getline(cin, line);
        istringstream sin(line);
        int W, H;
        sin >> W >> H;
        string temp;
        vector<string> words;
        while (sin >> temp) {
            words.push_back(temp);
        }
        // solve and output
        int answer = solve(W, H, words);
        cout << "Case #" << i+1 << ": " << answer << endl;
    }
}
