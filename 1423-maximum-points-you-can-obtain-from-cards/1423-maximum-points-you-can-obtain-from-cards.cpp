class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int size = cardPoints.size();
        vector<int> prefix(size,0);
        vector<int> suffix(size,0);
        prefix[0] = cardPoints[0];
        suffix[size-1] = cardPoints[size-1];
        for(int i=1;i<size;i++){
            prefix[i] = cardPoints[i] + prefix[i-1];
            suffix[size-i-1] = suffix[size-i] + cardPoints[size-i-1];
        }
        int MAX = 0;
        for(int i=0;i<=k;i++){
            if(i==0){
                MAX = max(MAX,suffix[size-k]);
            }
            else if(i==k){
                MAX = max(MAX,prefix[k-1]);            
            }
            else{
                MAX = max(MAX,suffix[size-(k-i)]+prefix[i-1]);
            }
        }
        return MAX;
    }
};