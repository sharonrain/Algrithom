class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      wordList.push_back(beginWord);
      int N = wordList.size();
      int start = N-1;
      int end = 0;
      while(end<N && wordList[end] != endWord) {
        end++;
      }
      if (end == N) return 0;
      vector<vector<int>> graphic = buildGraphic(wordList);
      return getShortestPath(graphic, start, end);
    }

    vector<vector<int>> buildGraphic(vector<string> wordList) {
      int N = wordList.size();
      vector<vector<int>> graphic(N, vector<int>());
      for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
          if (isConnect(wordList[i], wordList[j])) {
            graphic[i].push_back(j);
          }
        }
      }
      return graphic;
    }

    bool isConnect(string s1, string s2) {
      int diffCnt = 0;
      for (int i=0;i<s1.length() && diffCnt<=1;i++) {
        if (s1[i] != s2[i]) {
          diffCnt++;
        }
      }
      return diffCnt == 1;
    }

    int getShortestPath(vector<vector<int>> graphic, int start, int end) {
      queue<int> q;
      vector<bool> marked(graphic.size(), false);
      q.push(start);
      marked[start] = true;
      int path = 1;
      while(!q.empty()) {
        int size = q.size();

        path++;
        while(size-- > 0) {
          int cur = q.front();
          q.pop();
          for (auto next: graphic[cur]) {
            if (next == end) {
              return path;
            }
            if (marked[next])
              continue;
            marked[next] = true;
            q.push(next);
          }
        }
      }
      return 0;
    }
};