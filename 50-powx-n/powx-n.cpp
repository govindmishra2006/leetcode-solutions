class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n; // Use long long to avoid overflow when converting negative to positive
        
        if (nn < 0) {
            nn = -nn;
        }
        
        while (nn > 0) {
            if (nn % 2 == 1) { // If nn is odd
                ans = ans * x;
                nn = nn - 1;
            } else { // If nn is even
                x = x * x;
                nn = nn / 2;
            }
        }
        
        // If the original exponent was negative, invert the answer
        if (n < 0) {
            ans = (double)(1.0) / (double)(ans);
        }
        
        return ans;
    }
};