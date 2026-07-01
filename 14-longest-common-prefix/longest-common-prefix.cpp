class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string str1 = strs[0];
        string str2 = strs[n-1];
        int index = 0;
        for(int i=0;i<min(str1.length(), str2.length());i++){
            if(str1[i] == str2[i]){
                index++;
            }
            else{
                return str1.substr(0,index);
            }
        }
        return str1.substr(0,index);
    }
};