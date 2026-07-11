class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum = 0;
        int rightsum = 0;
        int totalSum = 0;
        int maxSum = 0;
        int n = cardPoints.size();
        for(int i=0;i<k;i++)
        {
            leftsum  = leftsum + cardPoints[i];
        }
        maxSum = leftsum;
        for(int i=k-1;i>=0;i--)
        {
            leftsum = leftsum - cardPoints[i];
            rightsum = rightsum +  cardPoints[n-1];
            n--;
            totalSum = leftsum + rightsum;
            maxSum = max(maxSum,totalSum);
        }
        return maxSum;
    }
};