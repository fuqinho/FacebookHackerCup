#include <iostream>
#include <sstream>

bool solve(std::string s) {
    int depth_max = 0, depth_min = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '(') {
            depth_max++;
            depth_min++;
        }
        else if (s[i] == ')') {
            depth_max--;
            depth_min--;
        }
        // ":)"は閉じ括弧に解釈してもよいので、最小のネストの深さだけ1減らす
        else if (i < s.size()-1 && s.substr(i,2) == ":)") {
            depth_min--;
            i++;
        }
        // ":("は開き括弧に解釈してもよいので、最大のネストの深さだけ1増やす
        else if (i < s.size()-1 && s.substr(i,2) == ":(") {
            depth_max++;
            i++;
        }
        // 途中でネストの深さがどうやっても負になるならもうあかん
        if (depth_max < 0) return false;
        depth_min = std::max(0, depth_min);
    }
    // 解釈次第で最終的にネストの深さを0にできるならOK
    return depth_min <= 0 && depth_max >= 0;
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    int T; ss >> T;
    for (int t = 1; t <= T; t++) {
        std::getline(std::cin, line);
        std::cout << "Case #" << t << ": " << (solve(line) ? "YES" : "NO") << std::endl;
    }
}
