class Solution {
public:
    bool checkZeroOnes(string s) {
        int ones = 0, zeros = 0;
        char prevChar = s[0];
        int charFreq = 0;
        for(auto chr: s){
          if(chr == prevChar) charFreq++;
          else{
            if(prevChar == '0') zeros = max(zeros, charFreq);
            else                ones  = max(ones,  charFreq);
            charFreq = chr;
          }
          prevChar = chr;
        }
        if(prevChar == '0') zeros = max(zeros, charFreq);
        else                ones  = max(ones,  charFreq);

        return ones > zeros;
    }
};
