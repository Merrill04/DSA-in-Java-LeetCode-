class Solution {
public:
    int minimumPushes(string word) {
/*
//Brute force:-
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
*/
        vector<int> freq(26, 0);
        int ans = 0;

        for(int i = 0; i < word.length(); i++){
            freq[word[i] - 'a'] += 1;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int count = 0; 

        for(int i = 0; i < freq.size(); i++){
            if(count <= 7 && freq[i] != 0){
                ans += (freq[i] * 1);
                count++;
            }else if(count > 7 && count <= 15 && freq[i] != 0){
                ans += (freq[i] * 2);
                count++;
            }else if(count > 15 && count <= 23 && freq[i] != 0){
                ans += (freq[i] * 3);
                count++;
            }else if(count > 23 && count <= 25 && freq[i] != 0){
                ans += (freq[i] * 4);
                count++;
            }
        }

        return ans;
    }
};