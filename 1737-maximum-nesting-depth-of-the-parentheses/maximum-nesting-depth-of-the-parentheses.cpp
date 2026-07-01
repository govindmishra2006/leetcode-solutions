class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int max_count = 0;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                count++;
                if(count > max_count){
                    max_count = count;
                }
            }
            else if(s[i] == ')'){
                count--;
            }
        }
        return max_count;
    }
};