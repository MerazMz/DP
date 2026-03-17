class Solution {
public:
    bool isPalin(string str){
        int st=0,end=str.size()-1;
        while(st<end){
            if(str[st]!=str[end]) return false;
            st++;
            end--;
        }
        return true;
    }
    void rec(string s, vector<string>& partition , vector<vector<string>>& ans){
        if(s==""){
            ans.push_back(partition);
            return;
        }

        for(int i=0;i<s.size();i++){
            string part = s.substr(0,i+1);
            if(isPalin(part)){
                partition.push_back(part);
                rec(s.substr(i+1),partition,ans);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        rec(s,partition,ans);
        return ans;
    }
};