// Реализуйте функцию void Reverse(vector<int>& v), которая переставляет элементы вектора в обратном порядке.
// #indlude <algorithm>

void Reverse(vector<int>& v){
  auto beg = v.begin();
  auto en = v.end();

  while ((beg != en) && (beg != --en)) {
      std::iter_swap(beg++, en);
  }
}
