#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution {
public:
    string makeGood(string s) {
        if (s.size() == 0) return s;
        stack<char> st;

        for (auto &c: s) {
            if (st.empty()) st.push(c);
            else {
                if (st.top() == c || abs(st.top() - c) != 32) {
                    st.push(c);
                } else {
                    st.pop();
                }
            }
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return std::reverse(res.begin(), res.end()), res;
    }
};

int main() {
    Solution s;
    string str = "leEeetcode";
    cout << s.makeGood(str);
    return 0;
}
