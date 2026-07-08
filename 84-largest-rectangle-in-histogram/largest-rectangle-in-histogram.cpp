class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxRectangleArea = 0;
        int n = heights.size();
        vector<int> nse;
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if (st.empty()) {
                nse.push_back(n);
            } else {
                nse.push_back(st.top());
            }
            st.push(i);
        }
        reverse(nse.begin(), nse.end());

        vector<int> pse;
        stack<int> st2;
        for (int i = 0; i < n; i++) {
            while (!st2.empty() && heights[st2.top()] >= heights[i]) {
                st2.pop();
            }
            if (st2.empty()) {
                pse.push_back(-1);
            } else {
                pse.push_back(st2.top());
            }
            st2.push(i);
        }
        for(int i=0;i<n;i++)
        {
            int area = heights[i] * (nse[i]-pse[i]-1);
            maxRectangleArea = max(maxRectangleArea,area);
        }
        return maxRectangleArea;
    }
};