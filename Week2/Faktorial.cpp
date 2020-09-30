#include <iostream>

int Factorial(int);

int Factorial(int n){
  if(n!=1){
	  return(n * Factorial(n-1));
  }
  else{
    return 1;
  }
}
int main() {

  int n = 0;

  std::cin >> n;
  std::cout << Factorial(n);

  return 0;
}
