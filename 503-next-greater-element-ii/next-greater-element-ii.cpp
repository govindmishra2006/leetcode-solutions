class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> mge;
        int n = nums.size();
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) {

                if (st.empty())

                    mge.push_back(-1);

                else

                    mge.push_back(st.top());
            }
            st.push(nums[i % n]);
        }
        reverse(mge.begin(), mge.end());
        return mge;
    }
};