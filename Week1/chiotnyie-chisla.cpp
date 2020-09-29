#include <iostream>

int main(){
  int x = 0, y = 0;
  std::cin >> x >> y;

  while(x <= y){
    if (x % 2 == 0){
      std::cout << x++ << " ";
    }
    else x++;
  }
  return 0;
}
