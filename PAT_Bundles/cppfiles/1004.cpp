//Author: subond
//Time: 2016-12-17

// 使用DFS(深度优先搜索)
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[100];  //存储具有子节点的当前节点标识和其子节点标识
int book[100], maxdepth = -1;
void dfs(int index, int depth) {
  if(v[index].size() == 0) {
    book[depth]++;
    maxdepth = max(maxdepth, depth);
    return ;
  }
  for(int i = 0; i < v[index].size(); i++)
    dfs(v[index][i], depth + 1);
}
int main() {
  int n, m, k, node, c;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &node, &k);
    for(int j = 0; j < k; j++) {
      scanf("%d", &c);
      v[node].push_back(c);
    }
  }
  dfs(1,0);
  printf("%d", book[0]);
  for(int i = 1; i <= maxdepth; i++)
    printf(" %d", book[i]);
  return 0;
}
//使用BFS(广度优先搜索)
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int level[100], book[100], maxlevel = -1;
vector<int> v[100];
void bfs() {
  queue<int> q;
  q.push(1);
  level[1] = 0;
  while(!q.empty()) {
    int index = q.front();
    q.pop();
    maxlevel = max(level[index], maxlevel);
    if(v[index].size() == 0)
      book[level[index]]++;
    for(int i = 0; i < v[index].size(); i++) {
      q.push(v[index][i]);
      level[v[index][i]] = level[index] + 1;
    }
  }
}
int main() {
  int n, m, k, node, c;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &node, &k);
    for(int j = 0; j < k; j++) {
      scanf("%d", &c);
      v[node].push_back(c);
    }
  }
  bfs();
  printf("%d", book[0]);
  for(int i = 1; i <= maxlevel; i++)
    printf(" %d", book[i]);
  return 0;
}
