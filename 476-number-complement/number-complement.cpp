class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = 0;
        unsigned int t = num;

        while (t > 0) {
            mask = (mask << 1) | 1U;
            t >>= 1;
        }

        return num ^ mask;
    }
};