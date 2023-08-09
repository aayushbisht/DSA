class Solution {
public:
    int check(int mid, vector<int>arr, int p){
        for(int i=1;i<arr.size();i++){
            if(arr[i] - arr[i-1] <=mid){
                p--;
                i++;
            }
        }
        return p<=0;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int l = 0, r = nums[n-1] - nums[0], ans = r;
        
        while(l<=r){
            int mid = (l+r)>>1;
            if(check(mid,nums,p)){
                r = mid -1;
                ans = mid;
            }
            else l = mid+1;
            
        }
        return ans;
    }
};