class Solution {
public:
    int minimumPushes(string word) {
        vector<int> countarray;
        int ans = 0;

        sort(word.begin(), word.end());

        int count = 1;
        for(int i = 1; i < word.length(); i++){
            if(word[i] != word[i - 1]){
                countarray.push_back(count);
                count = 1;
            }else{
                count++;
            }
        }

        countarray.push_back(count);

        sort(countarray.begin(), countarray.end(), greater<int>());

        for(int i = 0; i < countarray.size(); i++){
            if(i <= 7){
                ans += (countarray[i] * 1);
            }else if(i > 7 && i <= 15){
                ans += (countarray[i] * 2);
            }else if(i > 15 && i <= 23){
                ans += (countarray[i] * 3);
            }else if(i > 23 && i <= 25){
                ans += (countarray[i] * 4);
            }
        }

        return ans;
    }
};