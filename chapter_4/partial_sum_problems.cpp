#include <iostream>
#include <vector>
using namespace std;

/****************
  部分和問題を再帰関数を用いる全探索で解きます。
  N個の正の整数を足し合わせて整数Wとすることができるかを判定します。
****************/

// bool値を返す関数 入力:N, W, N個の配列
bool func(int N, int W, const vector<int> &arr) {
  // if (W - arr[N] == 0) {
  //   return true;
  // }

  if (N == 0) {
    if (W == 0) return true;
    else return false;
  }

  if (func(N-1, W, arr)) return true;
  if (func(N-1, W-arr[N], arr)) return true;

  return false;
}

// メイン関数 入力:N, W, N個の自然数。 出力:"Yes"または"No"。
int main() {
  int N, W;
  cin >> N >> W;
  vector<int> arr(N);
  for (int i = 0; i < N; ++i) cin >> arr[i];

  if (func(N, W, arr)) cout << "Yes" << endl;
  else cout << "Yes" << endl;
  
}

