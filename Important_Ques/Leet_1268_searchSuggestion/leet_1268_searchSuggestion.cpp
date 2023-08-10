class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        int start,nstart=0;
        string s = "";
        sort(products.begin(),products.end());
        for(auto x : searchWord){
            vector<string>res;
            s += x;
            start = lower_bound(products.begin()+nstart,products.end(),s)-products.begin();
            for(int i=start;i<min(start+3,(int)products.size());i++){
                if(!products[i].compare(0,s.size(),s)){
                    res.push_back(products[i]);
                }
            }
            nstart = start;
            ans.push_back(res);
        }
        return ans;
        
    }
};