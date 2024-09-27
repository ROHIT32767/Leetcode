class MyCalendarTwo {
public:
    vector<pair<int,int>> bookings;
    MyCalendarTwo() {
        
    }
    bool check(vector<pair<int,int>> vect){
        sort(vect.begin(),vect.end());
        for(int i=1;i<vect.size();i++){
            if(vect[i].first<vect[i-1].second){
                return false;
            }
        }
        return true;
    }
    bool book(int start, int end) {
        int count = 0;
        vector<pair<int,int>> vect;
        for(int i=0;i<bookings.size();i++){
            int prev_start = bookings[i].first;
            int prev_end = bookings[i].second;
            int max_start = max(prev_start,start);
            int min_end = min(prev_end,end);
            if(max_start<min_end){
                vect.push_back(bookings[i]);
            }
        }
        bool flag =  check(vect);
        if(flag){
            bookings.push_back(make_pair(start,end));
        }
        return flag;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */