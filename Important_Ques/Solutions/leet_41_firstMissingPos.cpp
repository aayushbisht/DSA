class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int counter = 1;
//         int n = nums.size(),i=0;
//         for( i=0;i<nums.size();i++){
//             if(nums[i]<=0) continue;
//             if(nums[i] == counter){
//                 if(i+1<n and nums[i+1]!=nums[i])
//                 counter++;
//             }
//             else break;
            
//         }
//         return (i==n and nums[n-1]>0) ? counter+1 : counter; 
        int n = nums.size(), i=0;
        while(i<n){
            if(nums[i]>0 and nums[i]<=nums.size() and nums[i] != nums[nums[i] - 1]) swap(nums[i],nums[nums[i]-1]);
            else i++;
        }
        for(int i=0;i<n;i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};