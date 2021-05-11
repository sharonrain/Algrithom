class MapSum {
private:
  struct Node {
    vector<Node*> childs;
    int value;

    Node() {
        childs = vector<Node*>(26, NULL);
        value = 0;
    }
  };
  Node* root = new Node();
public:
    /** Initialize your data structure here. */
    MapSum() {

    }

    void insert(string key, int val) {
      insert(key, val, root);
    }

    void insert(string key, int val, Node* node) {
      if (node == NULL) return;
      if (key.length()==0) {
        node->value = val;
        return;
      }
      int index = indexForChar(key[0]);
      if (node->childs[index] == NULL) {
        node->childs[index] = new Node();
      }
      insert(key.substr(1), val, node->childs[index]);
    }

    int indexForChar(char c) {
      return c - 'a';
    }

    int sum(string prefix) {
      return sum(prefix, root);
    }

    int sum(string prefix, Node* node) {
      if (node == NULL) return false;
      if (prefix.length() != 0) {
        int index = indexForChar(prefix[0]);
        return sum(prefix.substr(1), node->childs[index]);
      }
      int sum = node->value;

      for(auto child: node->childs) {
        sum += this->sum(prefix, child);
      }
      return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */