class Solution {
public:
    int divide(int dividend, int divisor) {
        long long  ans = 0;
        bool sign = true;
        if(dividend == divisor) return 1;
        if(dividend >= 0 && divisor < 0)
        {
            sign = false;
        }
        if(dividend <= 0 && divisor > 0)
        {
            sign = false;
        }
        long long  n = llabs((long long) dividend);
        long long d = llabs((long long)divisor);
        while(n >= d)
        {
            int cnt = 0;
            while(n >= (d << (cnt + 1)))
            {
                cnt++;
            }
            ans += (1LL << cnt);
            n = n - (d*  (1LL<< cnt));
        }
        if(ans >= (1LL << 31)-1 && sign == true)
        {
            return INT_MAX;
        }
        else if(ans >= (1LL << 31) && sign == false)
        {
            return INT_MIN;
        }
        if(!sign) ans = -ans;
        return (int)ans;

    }
};