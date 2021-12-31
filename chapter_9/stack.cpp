# include <iostream>
# include <vector>
using namespace std;

const int MAX = 10000; // スタック配列の最大サイズ

int st[MAX]; // スタックを表す配列
int top = 0; // スタックの先頭を表す添字

// スタックを初期化する
void init() {
	top = 0; // スタックの添字を初期位置に
}

// スタックが空かどうかを判定する
bool isEmpty() {
	return (top == 0); // スタックサイズが0かどうか
}

// スタックが満杯かどうか判定する
bool isFull() {
	return (top == MAX);
}

// push 
void push(int x) {
	if (isFull()) {
		cout << "error: stack is full." << endl;
		return;
	}
	st[top] = x; // xを格納して
	++top; // topを進める
}

// pop
int pop() {
	if (isEmpty()) {
		cout << "error: stack is full." << endl;
		return -1;
	}
	--top; // topをデクリメントして
	return st[top]; // topの位置にある要素を返す
}

int main() {
	init(); // スタックを初期化

	push(3); // スタックに3を追加する {} -> {3}
	
	push(5); // スタックに5を追加する {3} -> {3, 5}
	push(7); // スタックに7を追加する {3, 5} -> {3, 5, 7}

	cout << pop() << endl; // {3, 5, 7} -> {3, 5} で 7を出力
	cout << pop() << endl; // {3, 5} -> {3} で 5を出力
	
	push(9); // スタックに9を追加する {3} -> {3, 9}
}