class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> results;
        if (root == NULL)
            return results;
        vector<int> paths;
        backTracking(root, results, paths);
        return results;
    }

    void backTracking(TreeNode* root, vector<string>& results, vector<int>& paths) {
        if (root == NULL) return;
        paths.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
            results.push_back(buildPaths(paths));
        else {
            backTracking(root->left, results, paths);
            backTracking(root->right, results, paths);
        }
        paths.pop_back();
    }
    string buildPaths(vector<int>& paths) {
        string result;
        for (int i=0;i<paths.size();i++) {
            result+=to_string(paths[i]);
            if (i != paths.size()-1)
                result += "->";
        }
        return result;
    }
};