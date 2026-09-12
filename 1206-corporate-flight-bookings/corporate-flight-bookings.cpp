class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n, 0);
        vector<int> diff(n+1, 0);

        for(int i = 0; i < bookings.size(); i++){
            diff[bookings[i][0] - 1] += bookings[i][2];
            diff[bookings[i][1]] -= bookings[i][2];
        }

        int sum = 0;

        for(int i = 0; i < diff.size() - 1; i++){
            sum += diff[i];
            v[i] = sum;
        }

        return v;
    }
};