class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum =0,count=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum == k){
                count++;
            }
            if(m.find(sum-k)!=m.end()){
                count+=m[sum-k];
            }
            m[sum]++;
            
        }
        return count;
    }
};