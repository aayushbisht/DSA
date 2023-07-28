class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        stack<int>stMax;
        stack<int>stMin;
        vector<int>prevSmaller(n,0),prevGreater(n,0),nextSmaller(n,0),nextGreater(n,0);
        for(int i=0;i<n;i++){
            while(stMin.size() and nums[stMin.top()]>=nums[i]) stMin.pop();
            while(stMax.size() and nums[stMax.top()]<=nums[i]) stMax.pop();
            if(stMin.size()) prevSmaller[i] = i-stMin.top();
            else prevSmaller[i] = i+1;
            if(stMax.size()) prevGreater[i] = i-stMax.top();
            else prevGreater[i] = i+1;
            stMin.push(i);
            stMax.push(i);
        }
        while(!stMin.empty()) stMin.pop();
        while(!stMax.empty()) stMax.pop();
          for(int i=n-1;i>=0;i--){
            while(stMin.size() and nums[stMin.top()]>nums[i]) stMin.pop();
            while(stMax.size() and nums[stMax.top()]<nums[i]) stMax.pop();
            if(stMin.size()) nextSmaller[i] = stMin.top()-i;
            else nextSmaller[i] = n-i;
            if(stMax.size()) nextGreater[i] = stMax.top()-i;
            else nextGreater[i] = n-i;
            stMin.push(i);
            stMax.push(i);
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long max = prevGreater[i]*nextGreater[i];
            long long min = prevSmaller[i]*nextSmaller[i];
            ans += nums[i]*(max - min);
        }
        return ans;
    }
};