class FoodRatings {
public:
    unordered_map<string,int> foodrating;
    unordered_map<string,string> foodcuisine;
    unordered_map<string,set<pair<int,string>>> M;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int size = foods.size();
        for(int i=0;i<size;i++)
        {
            foodrating[foods[i]] = ratings[i];
            foodcuisine[foods[i]] = cuisines[i];
            M[cuisines[i]].insert({-ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        M[foodcuisine[food]].erase(M[foodcuisine[food]].find({-foodrating[food],food}));
        foodrating[food] = newRating;
        M[foodcuisine[food]].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        auto fooditem = *(M[cuisine].begin());
        return fooditem.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */