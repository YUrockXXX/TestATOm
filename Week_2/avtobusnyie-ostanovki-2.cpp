#include <iostream>
#include <vector>
#include <map>
#include <string>
// class bus{
// private:
//   std::string bus;
//   std::vector<std::string> stops;
// public:
//   void NEW_BUS(const std::string, const std::vector<std::string>);
//   void Print
// };
void PrintMapB(std::map <std::string, std::vector<std::string> > mp){
  for (const auto& item : mp) {
    std::cout << "Bus " << item.first << ": " ;
    for(const auto& item_second : item.second){
      std::cout << item_second << " "  ;
    }
    std::cout << '\n';
  }
}
void PrintMapS(std::map <std::string, std::vector<std::string> > mp){
  for (const auto& item : mp) {
    std::cout << "Bus " << item.first << ": " ;
    for(const auto& item_second : item.second){
      std::cout << item_second << " "  ;
    }
    std::cout << '\n';
  }
}
void PrintVector(std::vector<std::string> vec){
  for(const auto& item_second : vec){
    std::cout << item_second << " "  ;
  }
  std::cout << '\n';
}
void PrintVectorS(std::vector<std::string> vec,std::string bus){
  if(vec.size() == 1){
    std::cout << "no interchange" << '\n';
    return ;
  }
  for(const auto& item_second : vec){
    if(item_second != bus)
      std::cout << item_second << " "  ;
  }
  std::cout << '\n';
}
int main(){
  int num_oper = 0;//количество запросов
  std::cin >> num_oper;

  std::map<std::vector<std::string>,int> route;
  // std::map<std::string, std::vector<std::string>> stop_buses;

  for (int i = 0; i < num_oper; ++i) {
    int number_of_stops;
    std::cin >> number_of_stops;

    std::vector<std::string> stops;

    for(int i = 0; i < number_of_stops; i++){
      std::string stop;
      std::cin >> stop;
      stops.push_back(stop);
    }

    if(route.find(stops) == route.end()){
      int num_of_routes = route.size() + 1;
      route[stops] = num_of_routes;
      std::cout << "New bus " << num_of_routes << '\n';
    }
    else{
      std::cout << "Already exists for " << route[stops]<< '\n';
    }




  }
  return 0;
}
