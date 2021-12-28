#include <iostream>
#include <vector>
using namespace std;

// template
template<class T> void chmin(T& a, T b) {
  // 小さい方に更新
  if (a > b) {
    a = b;
  }
}

const long long INF = 1LL << 60; // 2^60

// 緩和を意識した解法
int main() {
  // 入力：N, N種の高さ h()
  int N;
  cin >> N;
  vector<long long> h(N);
  for (int i = 0; i < N; ++i) cin >> h[i];

  // 初期化（INF）
  vector<long long> dp(N, INF);

  // 初期条件
  dp[0] = 0;

  // ループ 配列の値は、そのインデックスに辿り着くまでのコストの総和の最小値となるようにする
  for (int i = 1; i < N; ++i) {
    chmin(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
    if (i > 1) {
      chmin(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
    }
  }

}