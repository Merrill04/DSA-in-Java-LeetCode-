class Solution {
public:
    int maxProduct(int n) {
        int max = -1;
        vector<int> v;

        while(n > 0){
            v.push_back(n % 10);
            n /= 10;
        }

        for(int i = 0; i < v.size()-1; i++){
            for(int j = i+1; j < v.size(); j++){
                if(v[i] * v[j] > max){
                    max = v[i] * v[j];
                }
            }
        }

        return max;
    }
};