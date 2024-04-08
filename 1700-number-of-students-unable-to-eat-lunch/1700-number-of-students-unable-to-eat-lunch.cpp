class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ones = 0;
        int zeroes = 0;
        for(int i=0;i<students.size();i++){
            if(students[i]){
                ones++;
            }
            else{
                zeroes++;
            }
        }
        int size = sandwiches.size();
        for(int i=0;i<sandwiches.size();i++){
            int val = sandwiches[i];
            if(val==1){
                if(ones){
                    ones--;
                }
                else{
                    return size-i;
                }
            }
            else{
                if(!zeroes){
                    return size-i;
                }
                else{
                    zeroes--;
                }
            }
        }
        return 0;
    }
};