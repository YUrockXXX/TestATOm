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
  int sum_of_temp = 0;

  std::cin >> num_of_days ;

  std::vector<int> imput_v(num_of_days);

  for(int i = 0; i < num_of_days; i++){
    int temp_of_day = 0;
    std::cin >> temp_of_day;
    sum_of_temp += temp_of_day;
    imput_v[i] = temp_of_day;
  }
  int ev_temp = sum_of_temp/num_of_days;
  int num_of_warm = 0;

  for(int i = 0; i < num_of_days; i++){
    if (imput_v[i] > ev_temp){
      num_of_warm++;
    }
  }
  std::cout << num_of_warm << '\n';
  for(int i = 0; i < num_of_days; i++){
    if (imput_v[i] > ev_temp){
      std::cout << i << " ";
    }
  }
  // PrintVector(imput_v);

  return 0;
}
