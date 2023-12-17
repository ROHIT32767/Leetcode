class NumberContainers {
public:
    // index to number
    unordered_map<int,int> index_array;
    // number to index
    unordered_map <int,set<int>> num_array; 
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(index_array.find(index)!=index_array.end())
        {
            int initial_number = index_array[index];
            num_array[initial_number].erase(num_array[initial_number].find(index));
        }
        index_array[index] = number;
        num_array[number].insert({index});
    }
    
    int find(int number) {
        if(num_array[number].size()==0)
        {
            return -1;
        }
        auto it = *num_array[number].begin();
        return it;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */