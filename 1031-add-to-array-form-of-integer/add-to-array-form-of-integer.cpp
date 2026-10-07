class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size() - 1;
        int carry = 0;

        while (i >= 0 && (k > 0 || carry > 0)) {
            int t = num[i] + (k % 10) + carry;

            num[i] = t % 10;
            carry = t / 10;

            k /= 10;
            i--;
        }

        while (k > 0) {
            int t = (k % 10) + carry;

            num.insert(num.begin(), t % 10);
            carry = t / 10;

            k /= 10;
        }

        while (carry > 0) {
            num.insert(num.begin(), carry % 10);
            carry /= 10;
        }

        return num;
    }
};