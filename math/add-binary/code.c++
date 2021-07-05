class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        string str = "";

        while(i >= 0 || j>=0 || carry == 1) {
            if (i>=0 && a[i--] == '1') {
                carry++;
            }
            if (j>=0 && a[j--] == '1') {
                carry++;
            }

            str += to_string(carry % 2);
            carry/=2;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};