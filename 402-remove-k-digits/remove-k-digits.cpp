class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();
        if (k == n) {
            return "0";
        }
        string ans = "";
        st.push(num[0]);
        for (int i = 1; i < n; i++) {
            if (k > 0) {
                while (!st.empty() && k > 0 && st.top() > num[i]) {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            } else {
                st.push(num[i]);
            }
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int m = ans.length();
        int i = 0;

        while (i < ans.size() && ans[i] == '0')
            i++;
        ans = ans.substr(i);
        if (ans.empty())
            return "0";
        return ans;
    }
};