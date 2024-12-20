#include <iostream>
#include <vector>

template<typename T>
void print_vec(const std::vector<T>& v) {
  for (size_t i{}; i < v.size(); i++) {
    std::cout << v[i];
    if (i != v.size() - 1) {
      std::cout << ",";
    }
  }
}

// 空欄(3)
size_t binarysearch(const std::vector<int>& v, int a){
    int f{0}, l{int(v.size() - 1)};
    std::cout << "##binary search begin\n";
    while (f <= l){
        int m{(f + l) / 2};
        std::cout << "f l = " << f << " " << l << std::endl;
        if(v[m]<a) f = m + 1;
        else l = m - 1;
    }
    std::cout << "##binary search end\n";
    return f;
}
// 空欄(2)
std::vector<size_t> find_indices(const std::vector<int>& v, int a, int b){
    size_t index{binarysearch(v,a)};
    std::cout << "##linear search begin\n";
    std::vector<size_t> indices;
    for (; index < v.size() && v[index] <= b; index++){
        std::cout << index << std::endl;
        indices.push_back(index);
    }
    std::cout << "##linear search end\n";
    return indices;
}

int main() {
  std::vector<int> v{1, 2, 5, 7, 9, 10, 14, 17, 21, 25};
  std::cout << "v={";
  print_vec(v);
  std::cout << "}\n";

  int a{}, b{};
  std::cout << "Input integers a and b: ";
  std::cin >> a >> b;
  // 空欄(1)
  if (a>b) std::swap(a, b);

  std::cout << "@Debug: a=" << a << "," << "b=" << b << "\n";

  std::vector<size_t> I{find_indices(v, a, b)};
  std::cout << "I={";
  print_vec(I);
  std::cout << "}\n";
  return 0;
}