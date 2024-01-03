class Solution {
public:
    int num_ones(string s)
    {
        int size = s.size();
        int count = 0;
        for(int i=0;i<size;i++)
        {
            if(s[i]=='1')
            {
                count++;
            }
        }
        return count;
    }
    int numberOfBeams(vector<string>& bank) {
        int size = bank.size();
        int prev_ones = 0;
        int prev_index = -1;
        int beams = 0;
        if(num_ones(bank[0])!=0)
        {
            prev_ones=num_ones(bank[0]);
            prev_index = 0;
        }
        for(int i=1;i<size;i++)
        {
            int check = num_ones(bank[i]);
            if(check)
            {
                if(prev_index!=-1)
                {
                    beams+=check*prev_ones;
                }
                prev_index = i;
                prev_ones = check;
            }
        }
        return beams;
    }
};