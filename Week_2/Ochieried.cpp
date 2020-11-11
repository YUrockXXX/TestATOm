// Люди стоят в очереди, но никогда не уходят из её начала,
// зато могут приходить в конец и уходить оттуда.
// Более того, иногда некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.
//
// Будем считать, что люди в очереди нумеруются целыми числами, начиная с 0.
//
// Реализуйте обработку следующих операций над очередью:
//
// WORRY i: пометить i-го человека с начала очереди как беспокоящегося;
// QUIET i: пометить i-го человека как успокоившегося;
// COME k: добавить k спокойных человек в конец очереди;
// COME -k: убрать k человек из конца очереди;
// WORRY_COUNT: узнать количество беспокоящихся людей в очереди.
// Изначально очередь пуста.


#include <iostream>
#include <vector>
#include <string>
// #include "str_switch.h"

int main(){
  int num_of_operations = 0;
  std::cin >> num_of_operations;
  std::vector<bool> queue = {};

  for (int i = 0; i < num_of_operations; i++){

    std::string instr;
    std::cin >> instr;

    if (instr == "COME"){
      int num = 0;
      std::cin >> num;
      if(num > 0){
        for(int i = 0; i < num;i++){
          queue.push_back(false);
        }
      }
      else{
        for(int i = 0;i < -num;i++){
          queue.pop_back();
        }
      }
    }
    else if(instr == "WORRY_COUNT"){
      int size = queue.size();
      int sum = 0;
      for(int i = size - 1; i >= 0; i--){
        if(queue[i] == true)
          sum++;
      }
      std::cout << sum << '\n';
    }
    else if(instr == "WORRY"){
      int n = 0;
      std::cin >> n;
      queue[n] = true;
    }
    else if(instr == "QUIET"){
      int n = 0;
      std::cin >> n;
      queue[n] = false;
    }
    else {
      exit(1);
    }
  }
  return 0 ;
}
