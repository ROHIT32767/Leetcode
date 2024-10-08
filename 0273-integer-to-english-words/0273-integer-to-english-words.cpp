class Solution {
public:
    string recursion(int num){
        map<int, string> M;
        if(num==0){
            return "";
        }
        vector<string> vect = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred", "Thousand", "Million", "Billion"};
        vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000, 1000000, 1000000000};
        int size = vect.size();
        for (int i = 0; i < size; i++)
        {
            M[nums[i]] = vect[i];
        }
        string s;
        if (num <= 20)
        {
            s = M[num];
        }
        else if(num<100){
            s = M[num/10*10] + " " + M[num%10];
        }
        else if(num<1000){
            s = M[num/100] + " " + M[100] + " " + recursion(num%100);
        }
        else if(num<1000000){
            s = recursion(num/1000) + " " + M[1000] + " " + recursion(num%1000);
        }
        else if(num<1000000000){
            s = recursion(num/1000000) + " " + M[1000000] + " " + recursion(num%1000000);
        }
        else{
            s = recursion(num/1000000000) + " " + M[1000000000] + " " + recursion(num%1000000000);
        }
        if(s[s.size()-1]==' '){
            s.pop_back();
        }
        return s;
    }
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        return recursion(num);
    }
};