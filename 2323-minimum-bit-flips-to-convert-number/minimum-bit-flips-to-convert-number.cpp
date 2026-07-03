class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = (start ^ goal);
        int minFlips = 0;
        while(ans)
        {
            if((ans & 1) == 1)
            {
                minFlips += 1;
            }
            ans = ans >> 1;
        }
        return minFlips;
    }
};