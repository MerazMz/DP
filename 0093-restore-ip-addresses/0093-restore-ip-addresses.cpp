class Solution {
public:
    bool isValidSegment(string s){
        if (s.size() > 1 && s[0] == '0') return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }
    // Backtracking function to generate all possible valid IP addresses.
    // idx   → current index in the string (how much of string is used)
    // count → number of parts (segments) formed so far (max 4)
    // path  → current IP being built (with dots)
    // ans   → stores all valid IP addresses
    // At each step, we try taking 1 to 3 digits as the next segment,
    // check if it forms a valid number (0–255, no leading zero),
    // and recursively build the remaining parts.
    // When exactly 4 parts are formed and entire string is used,
    // we add the current path to the answer.
    void rec(string& s, int idx, int count, string path, vector<string>& ans){
        if( idx == s.size() and count==4){
            path.pop_back();
            ans.push_back(path);
            return;
        }
        if(count==4 or idx==s.size()) return;

        for(int len=1;len<=3;len++){
            if(idx+len>s.size()) break;

            string partition = s.substr(idx,len);
            if(isValidSegment(partition)){
                rec(s,idx+len,count+1,path+partition+'.',ans);
            }
        }

    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        rec(s,0,0,"",ans);
        return ans;
    }
};