class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        double avg,sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(i+1==k){
                avg = sum/k;
                if(avg>=threshold) count++;
            }
            else if(i>=k){
                sum -= arr[i-k];
                avg = sum/k;
                if(avg>=threshold) count++;
            }
        }
        return count;
    }
};