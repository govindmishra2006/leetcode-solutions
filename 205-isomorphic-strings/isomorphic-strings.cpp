class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> charMap;
        unordered_set<char> used;
        for(int i=0;i<s.length();i++){
            if(charMap.find(s[i])!=charMap.end()){
                if(charMap[s[i]] != t[i])
                {
                    return false;
                }
            }
            else{
                if(used.count(t[i])){
                    return false;
                }
                charMap[s[i]] = t[i];
                used.insert(t[i]);
            }
        }
        return true;
    }
};