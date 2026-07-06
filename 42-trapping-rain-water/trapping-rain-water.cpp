class Solution {
   public:
    int trap(vector<int> &height) {
        int total = 0;
        int n = height.size();

        if (n == 0) return 0;

        vector<int> prefixMax(n);
        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            if (height[i] >= prefixMax[i - 1]) {
                prefixMax[i] = height[i];
            } else {
                prefixMax[i] = prefixMax[i - 1];
            }
        }
        vector<int> suffixMax(n);
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (height[i] >= suffixMax[i + 1]) {
                suffixMax[i] = height[i];
            } else {
                suffixMax[i] = suffixMax[i + 1];
            }
        }
        for (int i = 0; i < n; i++) {
            int minHeight = min(prefixMax[i], suffixMax[i]);
            total += minHeight - height[i];
        }

        return total;
    }
};