class Solution {
public:
    int dp[20];
    int solve(int n)
    {
        if(n==0||n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            cnt=cnt+solve(i-1)*solve(n-i);
        }
        return dp[n]=cnt;
    }
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};
