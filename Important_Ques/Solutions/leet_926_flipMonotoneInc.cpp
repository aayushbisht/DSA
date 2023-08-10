class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countOne = 0, countFlips = 0;
        for(auto x : s){
            if(x == '1') countOne++;
            else {
                countFlips++;
                countFlips = min(countFlips, countOne);
            }
        }
        return countFlips;
    }
};