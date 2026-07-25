class Solution {
public:
    int maxProduct(int n) {
        int max = 1;
        multiset<int, greater<int>> v;

        while(n > 0){
            v.insert(n % 10);
            n /= 10;
        }

        auto it = v.begin();
        max = max * (*it);
        ++it;
        max = max * (*it);

        return max;
    }
};