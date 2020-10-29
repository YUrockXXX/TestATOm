// Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
// Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.

#include <iostream>
#include <vector>

void PrintVector(const std::vector<int>& vec){
  for(auto i: vec){
    std::cout << i << std::endl;
  }
}
int main(){
  int num_of_days = 0;

  std::cin >> num_of_days ;

  std::vector<int> imput_v(num_of_days);

  for(int i = 0; i < num_of_days; i++){
    int temp_of_day = 0;
    std::cin >> temp_of_day;
    imput_v[i] = temp_of_day;
  }
  PrintVector(imput_v);

  return 0;
}
