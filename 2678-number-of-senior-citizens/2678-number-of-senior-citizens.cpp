class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(int i=0;i<details.size();i++){
            string t = details[i].substr(11,2);
            int p = stoi(t);
            if(p>60){
                count++;
            }
        }
        return count;
    }
};