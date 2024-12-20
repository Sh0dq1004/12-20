#include <iostream>
#include <vector>
#include <algorithm>

// vector<T> 型の変数の要素を一行で表示する関数
template<typename T>
void print_vec(const std::vector<T>& v) {
  for (const auto& e : v) {
    std::cout << e << " ";
  }
  std::cout << "\n";
}

struct Data {
  std::string label;
  int val;
};


std::ostream& operator<<(std::ostream& out, const Data& a) {
  return out << a.label << ":" << a.val;
}

// 空欄(1)
// 標準アルゴリズムのsort関数のために、
// Data 型に対する < 演算子を定義する。
// 第一引数 left, 第二引数 right として、
//  < で label 同士の比較、かつ <= で val 同士の比較を行う。


bool operator<(const Data& left, const Data& right){
    return left.label < right.label || (left.label == right.label && left.val <= right.val);
}

void test_sort(std::vector<Data> vd);
void test_search(std::vector<std::string>);

int main() {
  std::vector<Data> vd{
    {"a",1}, {"e",5}, {"b",4},
    {"b",5}, {"f",7},
  };
  test_sort(vd);

  std::vector<std::string> vs{"c++", "1", "prog", "exp","twelve"};
  test_search(vs);

  return 0;
}

void test_sort(std::vector<Data> vd) {
  // 空欄(2)
  // テキストに記載されている標準アルゴリズムを用いて、
  // vector<Data> 型の vd の要素の並びをソートする。
  // Data 型同士での < 演算子(つまり、空欄(1))の定義が必要になる。
  std::sort(vd.begin(), vd.end());

  std::cout << "vd(sorted): ";
  print_vec(vd);
}

void test_search(const std::vector<std::string> vs) {
  std::string key;
  std::cout << "Input string key: ";
  std::cin >> key;
  std::cout << "vs: ";
  print_vec(vs);

  // 空欄(3)
  // 変数 vs 内に変数 key と一致する要素が存在するかを判定する。
  // 判定には第12回講義で扱った標準アルゴリズムを必ず使用すること。
  // 出力方法は実行例を参照すること。
  // ヒント：複数行
  auto it{std::find(vs.begin(), vs.end(), key)};
  std::cout << "Key " << key << " is" << (it!=vs.end() ? "" : " not") << " found in vs."<<std::endl;
}
