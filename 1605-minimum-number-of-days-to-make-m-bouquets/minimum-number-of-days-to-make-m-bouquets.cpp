class Solution {
public:

    bool bouquetPossible(vector<int>& bloom_days, long long int bloom_day, int m, int k) {
        long long int bouquets = 0, flowers = 0;
        for(const int& day: bloom_days) {
            if(day <= bloom_day)
                ++flowers;
            else
                flowers = 0;
            if(flowers == k)
                ++bouquets, flowers = 0;
        }      
        return bouquets >= m;
    } 

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long int product = static_cast<long long int>(m) * k;
        if(product > bloomDay.size())
            return -1;  
        long long int low = 0, high = INT_MAX;
        while(low < high) {
            long long int bloom_day = low + (high - low) / 2;
            if(bouquetPossible(bloomDay, bloom_day, m, k))
                high = bloom_day;
            else
                low = bloom_day + 1;
        }
        return high;
    }
};