#include <cstdio>
#include <algorithm>
using namespace std;
const int inf = 99999999;
int n, m;
int e[505][505];
bool visit[505];
int book[505];
void dfs(int x) {
  if(visit[x] == true) {
    return ;
  } else {
    visit[x] = true;
    for(int i = 1; i <= n; i++) {
      if(!visit[i] == false && e[x][i] != inf) {
        dfs(i);
      }
    }
  }
}
int main() {
  fill(e[0], e[0] + 505 * 505, inf);
  fill(visit, visit + 505, false);
  fill(book, book + 505, 0);
  scanf("%d %d", &n, &m);
  int a, b, count = 0;
  for(int i = 0; i < m; i++) {
    scanf("%d %d", &a, &b);
    book[a]++;
    book[b]++;
    e[a][b] = e[b][a] = 1;
  }
  for(int i = 1; i <= n; i++) {
    count++;
    dfs(i);
  }
  int flag = 0;
  for(int i = 1; i <= n; i++) {
    if(book[i] % 2 != 0)
      flag = flag + 1;
  }
  for(int i = 1; i <= n; i++) {
    if(i == 1)
      printf("%d", book[i]);
    else
      printf(" %d", book[i]);
  }
  if(count == 1) {
    if(flag == 0) printf("\nEulerian");
    else if(flag == 2) printf("\nSemi-Eulerian");
    else printf("\nNon-Eulerian");
  } else {
    printf("\nNon-Eulerian");
  }
  return 0;
}
