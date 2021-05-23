class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
      vector<int> prefSum;
      int curSm = stones[0];
      auto stone = stones.begin();
      stone++; // since x>1  we have to pick atleast 2 stones which means prefSum[1] or onwards
      while(stone != stones.end()){
        curSm += *stone;
        prefSum.push_back(curSm);
        stone++;
      }
      int length = prefSum.size();

      // dp[i] is the maximum difference if the first player picks
      // the first element in stones[i:ln] by ignoring stones[:i] elements
      vector<int> dp(length, 0);
      dp[length-1] = prefSum[length-1];
      for(int ind = length-2; ind >= 0; ind--)
        dp[ind] = max(dp[ind+1], prefSum[ind] - dp[ind+1]);

      return dp[0]; // return the maximum difference possible
    }
};
