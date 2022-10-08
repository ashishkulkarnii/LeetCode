class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        if(n == 1) {
            return 1;
        }
        
        vector<int> candies(n, 0);
        
        for(int i = 1; i < n; ++i) {
            if(ratings[i-1] < ratings[i]) {
                candies[i] += candies[i-1] + 1;
            }
        }
        
        for(int i = n - 2; i >= 0; --i) {
            if(ratings[i+1] < ratings[i]) {
                if(candies[i] <= candies[i+1]) {
                    candies[i] = candies[i+1] + 1;
                }
            }
        }
        
        int offset = 1 - *min_element(candies.begin(), candies.end());
        
        return accumulate(candies.begin(), candies.end(), offset * n);
    }
};