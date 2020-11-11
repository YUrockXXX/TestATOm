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

  std::map<std::string, std::vector<std::string>> bus_stops;
  std::map<std::string, std::vector<std::string>> stop_buses;

  for (int i = 0; i < num_oper; ++i) {
    std::string oper;
    std::cin >> oper;

    if (oper == "NEW_BUS") {
      std::string bus_name = "";
      std::cin >> bus_name;
      int stop_count = 0;
      std::cin >> stop_count;

      std::vector<std::string> bus;

      for(int j = 0; j < stop_count; j++ ){
        std::string stop = "";
        std::cin >> stop;
        bus.push_back(stop);
        stop_buses[stop].push_back(bus_name);
      }
      bus_stops[bus_name] = bus;

    } else if (oper == "BUSES_FOR_STOP"){
      std::string stop_name = "";
      std::cin >> stop_name;
      if(stop_buses.empty()){
        std::cout << "NO stop"  << '\n';
      }
      else{
        PrintVector(stop_buses[stop_name]);
      }
    } else if (oper == "STOPS_FOR_BUS"){

      std::string bus_name = "";
      std::cin >> bus_name;

      if ( bus_stops.find(bus_name) == bus_stops.end() ) {
        std::cout << "NO bus" << '\n';// not found
      } else {
        for(const auto& item: bus_stops[bus_name]){
          std::cout << "Stop "  << item << ": ";
          PrintVectorS(stop_buses[item],bus_name);
        }
    }
    } else if (oper == "ALL_BUSES"){
      if(bus_stops.empty()){
        std::cout << "No buses" << std::endl;
      }else
      PrintMapB(bus_stops);
    }
  }
  return 0;
}
