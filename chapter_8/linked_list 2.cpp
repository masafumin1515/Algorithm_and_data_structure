# include <iostream>
# include <string>
# include <vector>
using namespace std;

// 連結リストの各ノードを表す構造体
struct Node {
  Node* next;
  string name;

  Node(string name_ = "") : next(NULL), name(name_) { }
};

// 番兵を表すノードをグローバル領域に置いておく
Node* nil;

// 初期化
void init() {
  nil = new Node();
  nil -> next = nil; // 初期状態ではnilがnilを指すようにする
}

// 連結リストを出力する
void printList() {
  Node* cur = nil -> next; // 先頭から出発
  for (; cur != nil; cur = cur -> next) {
    cout << cur -> name << " -> ";
  }
  cout << endl;
}

// ノードpの直後にノードvを挿入する
// ノードpのデフォルト引数をnilとしておきく
// そのため insert(v) を呼び出す操作はリストの先頭への挿入を表す
void insert(Node* v, Node* p = nil) {
  v -> next = p -> next;
  p -> next = v;
}

int main() {
  // 初期化
  init();

  // 作りたいノードの名前一覧
  // 最後尾のノード山本から順に挿入することに注意
  vector<string> names = {
    "yamamoto",
  };

  
}