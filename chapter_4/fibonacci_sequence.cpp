#include <iostream>
#include <vector>
using namespace std;

/****************
  フィボナッチ数列を求める再帰関数をメモ化します
****************/

// fibo(N)の答えをメモ化する配列
vector<long long> memo; 

// フィボナッチ数列を再帰関数で実装+メモ化します
long long fibo(int N) {
  if (N == 0) {
    return 0;
  }
  
  if (N == 1) {
    return 1;
  }

  if (memo[N] != -1) {
    return memo[N];
  }

  return memo[N] = fibo(N - 1) + fibo(N - 2);
}

// メイン関数 フィボナッチ数列に49を与えた時の計算結果を出力します
int main() {
  memo.assign(50, -1);
  
  fibo(49);

  for (int N = 2; N < 50; ++N) {
    cout << N << " 項目：" << memo[N] << endl;
  }
}



