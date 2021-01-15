class Solution {
  public:
      vector<TreeNode*> generateTrees(int n) {
          vector<TreeNode*> results;

          if (n < 1) return results;
          return generateSubTrees(1, n);
      }

      vector<TreeNode*> generateSubTrees(int s, int e) {
          vector<TreeNode*> res;
          if (s > e) {
            res.push_back(null);
            return res;
          }

          for (int i = s; i<= e; i++) {
            vector<TreeNode*> leftSubTrees = generateSubTrees(s, i-1);
            vector<TreeNode*> rightSubTrees = generateSubTrees(i+1, e);

            for (auto left:leftSubTrees)
              for (auto right: rightSubTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                res.push_back(root);
              }

          }
          return res;
      }

};