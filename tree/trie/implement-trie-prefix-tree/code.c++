class Trie {
private:
  struct Node {
    vector<Node*> childs;
    bool isLeaf;

    Node() {
        childs = vector<Node*>(26, NULL);
        isLeaf = false;
    }
  };
  Node* root = new Node();
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
      insert(word, root);
    }

    void insert(string word, Node* node) {
      if (node == NULL) return;
      if (word.length()==0) {
        node->isLeaf = true;
        return;
      }
      int index = indexForChar(word[0]);
      if (node->childs[index] == NULL) {
        node->childs[index] = new Node();
      }
      insert(word.substr(1), node->childs[index]);
    }

    int indexForChar(char c) {
      return c - 'a';
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
      return search(word, root);
    }

    bool search(string word, Node* node) {
      if (node == NULL) return false;
      if (word.length() == 0) return node->isLeaf;
      int index = indexForChar(word[0]);
      return search(word.substr(1), node->childs[index]);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
      return startsWith(prefix, root);
    }

    bool startsWith(string prefix, Node* node) {
      if (node == NULL) return false;
      if (prefix.length() == 0) return true;
      int index = indexForChar(prefix[0]);
      return startsWith(prefix.substr(1), node->childs[index]);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */