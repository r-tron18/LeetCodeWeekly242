#define INF_SPEED (int)(1e9 + 1)
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
      int lowSpeed = 1, highSpeed = INF_SPEED;
      while(lowSpeed < highSpeed){
        int midSpeed = (lowSpeed + highSpeed) / 2;
        if(check(dist, midSpeed, hour))
          highSpeed = midSpeed;
        else
          lowSpeed = midSpeed + 1;
      }

      if(lowSpeed == INF_SPEED) return -1;
      return lowSpeed;
    }

    bool check(vector<int>& dist, int speed, double hour){
      double totalTimeTaken = 0;
      for(int i=0; i<dist.size()-1; i++){
        int curTrainTime = (dist[i] + speed - 1) / speed;
        totalTimeTaken += curTrainTime;
      }
      totalTimeTaken += (double) dist.back() / speed;
      return totalTimeTaken <= hour;
    }
};
