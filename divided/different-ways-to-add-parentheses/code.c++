class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
      vector<int> results;
      for (int i = 0; i< input.length(); i++) {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' ) {
          vector<int> left = diffWaysToCompute(input.substr(0, i));
          vector<int> right = diffWaysToCompute(input.substr(i+1));

          for (int l: left)
            for(int r: right)
              switch (input[i]) {
                case '+':
                  results.push_back(l + r); break;
                case '-':
                  results.push_back(l - r); break;
                case '*':
                  results.push_back(l * r); break;
              }
        }
      }
      if  (results.size() == 0)
        results.push_back(atoi(input.c_str()));
      return results;
    }
};