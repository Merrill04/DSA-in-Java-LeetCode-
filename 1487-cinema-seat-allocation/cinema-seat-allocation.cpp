class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>> m;

        for(int i = 0; i < reservedSeats.size(); i++){
            if(m.find(reservedSeats[i][0]) != m.end()){
                m[reservedSeats[i][0]].push_back(reservedSeats[i][1]);
            }else{
                vector<int> v;
                v.push_back(reservedSeats[i][1]);
                m[reservedSeats[i][0]] = v;
            }
        }

        int res = 0;

        for(auto &i: m){
            if(i.second.size() >= 2){
                int s1 = 0;
                int s2 = 0;
                int s3 = 0;
                for(int j = 0; j < i.second.size(); j++){
                    if(i.second[j] >= 2 && i.second[j] <= 5){
                        s1++;
                    }

                    if(i.second[j] >= 4 && i.second[j] <= 7){
                        s2++;
                    }

                    if(i.second[j] >= 6 && i.second[j] <= 9){
                        s3++;
                    }
                }

                if(s1 == 0 && s2 == 0 && s3 == 0 ){
                    res += 2;
                }else if(s1 > 0 && s2 > 0 && s3 > 0){
                    res += 0;
                }else{
                    res += 1;
                }
            }else if(i.second.size() == 1){
                if(i.second[0] == 1 || i.second[0] == 10){
                    res += 2; 
                }else{
                    res += 1;
                }
            }
        }

        res += (2 * (n - m.size()));

        return res;
    }
};