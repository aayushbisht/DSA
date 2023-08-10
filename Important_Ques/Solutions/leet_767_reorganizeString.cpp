class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26);
        int maxFreq = 0,i=0;
        for(auto ch : s){
            freq[ch-'a']++;
            if(freq[ch-'a']>freq[maxFreq])
                maxFreq = (ch-'a');
        }
        if((s.size()+1)/2 < freq[maxFreq] ) return "";
        while(freq[maxFreq]){
            s[i] = ('a' + maxFreq);
            i += 2;
            freq[maxFreq]--;
        }
        for(int k=0;k<26;k++){
            while(freq[k]){
                if(i >=s.size()) i = 1;
                s[i] = ('a'+k);
                i += 2;
                freq[k]--;
            }
        }
        return s;
        
    }
    
};