# include <iostream>
# include <vector>
# include <queue>
using namespace std;
using Graph = vector<vector<int>>;

// グラフGにおいて、頂点 s を支点とした探索を行う
void search(const Graph &G, int s) {
  int N = (int)G.size(); // グラフの頂点数

  // グラフ探索のためのデータ構造
  vector<bool> seen(N, false); // 全頂点を「未訪問」に初期化する
  queue<int> todo; // 空の状態

  // 初期条件
  seen[s] = true; // sは探索済みとする
  todo.push(s); // todoはsのみを含む状態となる

  // todoが空になるまで探索を行う
  while(!todo.empty()) {
    // todoから値を取り出す
    int v = todo.front();
    todo.pop();

    // v からたどれる頂点を全て調べる
    for (int x : G[v]) {
      // すでに発見済みの頂点は探索しない
      if (seen[x]) continue;

      // 新たな頂点xを探索済みとして todo に挿入
      seen[x] = true;
      todo.push(x);
    }
  }
};