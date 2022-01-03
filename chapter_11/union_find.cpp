# include <iostream>
# include <vector>
using namespace std;

// Union Find
struct UnionFind {
  // par:各頂点の親頂点の番号 siz:各頂点が属する根付き木の頂点数
  vector<int> par, siz;

  // 初期化
  UnionFind(int n) : par(n, -1), siz(n, 1) {} // parの初期値は-1(親)、sizの初期値は1（一つだから）

  // 根を求める
  int root(int x) {
    if (par[x] == -1) return x; // xが根の場合はxを返す
    return par[x] = root(par[x]);
  }

  // xとyが同じグループに属するかどうか
  bool isSame(int x, int y) {
    return root(x) == root(y);
  };

  // xを含むグループとyを含むグループとを併合する
  bool unite(int x, int y) {
    // x, y をそれぞれ根まで移動する
    x = root(x); 
    y = root(y);

    // すでに同じグループの時は何もしない
    if (x == y) return false;

    // union by size (y側のサイズが小さくなるようにする)
    if (siz[x] < siz[y]) swap(x, y);

    // yをxの子とする
    par[y] = x;
    siz[x] += siz[y];
    return true;
  };

  // xを含むグループのサイズ
  int size(int x) {
    return siz[root(x)];
  }
};


int main() {
  UnionFind uf(7); // {0}, {1}, {2}, {3}, {4}, {5}, {6}
  
  uf.unite(1, 2); // {0}, {1, 2}, {3}, {4}, {5}, {6}
  uf.unite(2, 3); // {0}, {1, 2, 3}, {4}, {5}, {6}
  uf.unite(5, 6); // {0}, {1, 2, 3}, {4}, {5, 6}
  cout << uf.isSame(1, 3) << endl; // true
  cout << uf.isSame(2, 5) << endl; // false

  uf.unite(1, 6); // {0}, {1, 2, 3, 5, 6}, {4}
  cout << uf.isSame(2, 5) << endl; // false
}

