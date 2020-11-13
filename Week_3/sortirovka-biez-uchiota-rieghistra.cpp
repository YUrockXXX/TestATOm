#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

std::string str_tolower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return std::tolower(c); });
    return s;
}

bool compAbs(const std::string & first, const std::string& second){
  std::string first_transformed = str_tolower(first);
  std::string second_transformed = str_tolower(second);

  return first_transformed < second_transformed ? true : false;
}

int main(){

  int num = 0;
  std::cin >> num;

  std::vector<std::string> vec;
  for(int i = 0; i < num; i++){
    std::string temp;
    std::cin >> temp;
    vec.push_back(temp);
  }
  std::sort(vec.begin(),vec.end(),compAbs);
  for (const auto& i : vec) {
    std::cout << i << " " ;
  }
  return 0;
}
