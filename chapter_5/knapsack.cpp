#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T& a, T b) {
  if (a < b){
    a = b;
  }
}

int main() {
  // 入力
  // N:品物の個数, W:重さの総和の制限

  int N; long long W;
  cin >> N >> W;
  vector<long long> weight(N), value(N);
  // 各品物の重さと価値を定義
  for (int i=0; i<N; ++i) cin >> weight[i] >> value[i];

  // DP テーブル定義 dp:価値の総和の最大値
  vector<vector<long long>> dp(N+1, vector<long long>(W+1, 0))

  // DP ループ
  for (int i=0; i<N; ++i) {
    for (int w=0; w<=W; ++w) {
      // i番目の品物を選ぶ場合
      if (w-weight[i] >= 0) {
        chmax(dp[i+1][w], dp[i][w-weight[i]] + value[i]);
      }

      // i番目の品物を選ばない
      chmax(dp[i+1][w], dp[i][w]);
    }
  }

  // 最適値の出力
  cout << dp[N][W] << endl;
}