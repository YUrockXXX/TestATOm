// #include <iostream>
// #include <string>

bool IsPalindrom(std::string a){
  for (int i = 0;i < a.size();i++){
    if (a[i] != a[a.size()-1-i]){
      return false;
    }
  }
  return true;
}

// int main(){
//   std::string a = "";
//   std::cin >> a;
//   std::cout << IsPalindrom(a) << '\n';
//   return 0;
// }
