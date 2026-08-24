class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); i++){
            m[nums[i]] += 1;
        }

        if(m.size() < 3){
            int res = INT_MIN;
            for(auto &it : m){
                if(it.first > res){
                    res = it.first;
                }
            }

            return res;
        }

        long long max = LLONG_MIN;

        for(auto &i : m){
            if(i.first > max){
                max = i.first;
            }
        }

        m.erase(max);
        max = LLONG_MIN;

        for(auto &i : m){
            if(i.first > max){
                max = i.first;
            }
        }

        m.erase(max);

        int res = INT_MIN;

        for(auto &i : m){
            if(i.first > res){
                res = i.first;
            }
        }

        return res;
    }
};