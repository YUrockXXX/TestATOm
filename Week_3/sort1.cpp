#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
bool compAbs(const int& first,const int& second){

    return abs(first) < abs(second) ? true : false;
}
int main(){
  int num = 0;
  std::cin >> num;
  std::vector<int> vec;
  for(int i = 0; i < num; i++){
    int temp = 0;
    std::cin >> temp;
    vec.push_back(temp);
  }
  std::sort(vec.begin(),vec.end(),compAbs );
  for (const auto& i : vec) {
    std::cout << i << " " ;
  }
  return 0;
}
