#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
  std::vector<std::string> v ;
  std::string str;
  std::cin >> str;
  v.push_back(str);

  std::cout << v[0];

  return 0;
}
