#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

int main(){
  int num_oper = 0;//количество запросов
  std::cin >> num_oper;

  std::map<std::string,std::set<std::string>> sinonimy;
  // std::map<std::string, std::vector<std::string>> stop_buses;

  for (int i = 0; i < num_oper; ++i) {
    std::string oper;
    std::cin >> oper;

    if(oper == "ADD"){
      std::string first_word;
      std::string second_word;
      std::cin >> first_word >> second_word;
      sinonimy[first_word].insert(second_word);
      sinonimy[second_word].insert(first_word);

    }
    else if(oper == "COUNT"){
      std::string word;
      std::cin >> word;
      std::cout << sinonimy[word].size() << std::endl;
    }
    else if(oper == "CHECK"){
      std::string first_word;
      std::string second_word;
      std::cin >> first_word >> second_word;
      if (sinonimy[first_word].find(second_word) == sinonimy[first_word].end()){
        std::cout << "NO" << '\n';
      }
      else {
        std::cout << "YES" << '\n';
      }
    }

  }

  return 0;
}
