class Solution {

public:
    vector<int> NSE(vector<int>& arr) {

        int n = arr.size();

        vector<int> nse(n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] > arr[i]) {

                st.pop();
            }

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> PSE(vector<int>& arr) {

        int n = arr.size();

        vector<int> pse(n);

        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {

                st.pop();
            }

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        const int MOD = 1e9 + 7;

        vector<int> pse = PSE(arr);

        vector<int> nse = NSE(arr);

        long long sum = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - pse[i];

            long long right = nse[i] - i;

            sum = (sum + (left * right % MOD) * arr[i]) % MOD;
        }

        return sum;
    }
};