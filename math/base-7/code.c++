class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        bool isNegative = false;
        if (num == 0)
            return "0";

        if (num < 0) {
            num = -num;
            isNegative = true;
        }
        while(num != 0) {
            res += to_string(num % 7);
            num = num / 7;
        }
        if (isNegative) {
            res += '-';
        }
        reverse(res.begin(), res.end());

        return res;
    }
};