class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n, 0);

        for(int i = 0; i < bookings.size(); i++){
            for(int j = bookings[i][0] - 1; j < bookings[i][1]; j++){
                v[j] += bookings[i][2];
            }
        }

        return v;
    }
};