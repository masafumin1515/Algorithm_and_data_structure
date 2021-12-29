# include <iostream>
# include <vector>
# include <algorithm>
# include <functional>
using namespace std;

// 区間をpair<int, int>で表す <始端時刻 終端時刻>
using Interval = pair<int, int>;

// 区間を終端時間で大小比較する関数
bool cmp(const Interval &a, const Interval &b) {
  return a.second < b.second;
}

int main() {
  // 入力
  int N;
  cin >> N;
  vector<Interval> inter(N);
  for (int = 0; i < N; ++i) {
    cin >> inter[i].first >> inter[i].second;
  }

  // 終端時間が早い順にソートする
  sort(inter.begin(), inter.end(), cmp);

  // 貪欲に選ぶ
  int res = 0;
  int current_end_time = 0;
  for (int i = 0; i < N; ++i) {
    // 最後に選んだ区間と被るのは除く 現時点での最短終端時間より早い開始時刻を持つ区間の場合はスキップ
    if (inter[i].first < current_end_time) continue;

    ++res;
    current_end_time = inter[i].second;
  }
  cout << res <<endl;
}

