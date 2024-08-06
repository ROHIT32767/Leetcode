class Solution {
public:
    int minimumPushes(string word) {
        int size = word.size();
        int freq[26] = {0};
        for(int i=0;i<size;i++){
            int ch = word[i];
            freq[ch-97]+=1;
        }
        vector<int> vect;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                vect.push_back(freq[i]);
            }
        }
        sort(vect.begin(),vect.end());
        long long int sum = 0;
        for(int i=0;i<vect.size();i++){
            int index = vect.size()-i-1;
            int factor = i/8;
            factor++;
            sum+= vect[index]*factor;
        }
        return sum;
    }
};