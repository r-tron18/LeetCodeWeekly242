class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> queue1; // decreasing queue
        queue<int> queue2; // increasing queue
        int length = s.size();
        if(s[length-1] == '1') return false;
        queue2.push(length-1);
        for(int i=length-2; i>=0; i--){
            // pop from q1 if indices > i + maxJump
            while(queue1.size() && queue1.front() > i + maxJump) queue1.pop();
            // move from queue2 to queue1 if it happens to be in range of i
            while(queue2.size() && queue2.front() >= i + minJump){
                queue1.push(queue2.front()); queue2.pop();
            }
            if(queue1.size() && s[i] == '0') queue2.push(i);
        }

        while(queue2.size()){
            if(queue2.front() == 0) return true;
            queue2.pop();
        }
        return false;
    }
};
