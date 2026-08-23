class Solution {
public:
    bool sumGame(string num) {
        int sum1 = 0;
        int sum2 = 0;
        int c1 = 0;
        int c2 = 0;

        for(int i = 0; i < num.length(); i++){
            if(i < num.length() / 2){
                if(num[i] == '?'){
                    c1++;
                }else{
                    sum1 += num[i] - '0';
                }
            }else{
                if(num[i] == '?'){
                    c2++;
                }else{
                    sum2 += num[i] - '0';
                }
            }
        }

        if((c1 + c2) % 2 != 0){
            return true;
        }

        int left = (2 * sum1) + (9 * c1);
        int right = (2 * sum2) + (9 * c2);

        if(left == right){
            return false;
        }
        
        return true;
    }
};