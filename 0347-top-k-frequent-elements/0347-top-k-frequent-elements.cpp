class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int &num : nums) {
            mp [num]++;
        };
        vector<vector<int>> bucket(n+1);
//Index = freq
//value = elements
//bucket[i] = elements having i frequency
        for(auto &num: mp) {
            int element = num.first;
            int freq = num.second;
            bucket[freq].push_back(element);
        };
//result
//Pick elements from right to left from bucket to find max frequency element
        vector<int> result;
        for(int i = n; i>=0; i -- ) {
            if(bucket[i].size() == 0)
                continue;
            while(bucket[i].size() > 0 && k > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k --;
            };
        };
        return result;
    };
};