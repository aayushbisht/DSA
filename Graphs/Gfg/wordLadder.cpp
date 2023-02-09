  unordered_set<string>s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int ans = q.front().second;
            if(word == endWord) return ans;
            q.pop();
            for(int i=0;i<word.size();i++)
            {
                char ini = word[i];
                for(char ch = 'a';ch<='z';ch++)
                {
                    word[i] = ch;
                    if(s.find(word)!=s.end())
                    {
                        s.erase(word);
                        q.push({word,ans+1});
                    }
                }
                word[i] = ini;
            }
        }
        return 0;