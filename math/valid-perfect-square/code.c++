class Solution {
public:
    bool isPerfectSquare(int num) {
        long squre = 1;
        long diff = 3;
        while (squre < num) {
            squre += diff;
            diff +=2;
        }

        return squre == num;
    }
};