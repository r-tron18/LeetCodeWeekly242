class Solution:
    def stoneGameVIII(self, stones: List[int]) -> int:
        prefSum = []
        cur_sm = 0
        for it in stones:
            cur_sm += it
            prefSum.append(sm)
        pref = pref[1:] ## since x>1  we drop the first index
        ln = len(pref)

        ## dp[i] is the maximum difference if the first player picks
        ## the first element in stones[i:ln] by ignoring stones[:i] elements
        dp = [0]*(ln)
        dp[ln-1] = pref[ln-1]
        for i in range(ln-2, -1,-1):
            dp[i] = max(dp[i+1], pref[i] - dp[i+1])
        return dp[0] ## return the max difference a player can get
