#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <map>

std::string FindNameByYearHistory(const std::map<int, std::string>& nameSurname,const int year){
  std::string name = "";
  std::vector<std::string> anotherName;

  for(const auto& i : nameSurname){
    if(i.first <= year){
      name = i.second;
      anotherName.push_back(i.second);
    }
    else
      break;
  }
  std::string output, temp;
  output += "(";
  temp = name;

  for (auto item : anotherName) {
    if (item != temp) {
      temp = item;
      output +=  item;
    }
  }
  output += ")";
  if(output == "()"){
    return name;
  }
  return name + " " + output;

}
void PrintMap(std::map <int, std::string> mp){
  for (const auto& item : mp) {
    std::cout << "Year " << item.first << ": " << item.second << " "
    << item.second << "\n";
  }
}

class Person {
public:
  void ChangeFirstName(int year, const std::string& first_name) {
    nameByYear[year] = first_name;
  }
  void ChangeLastName(int year, const std::string& last_name) {
    surnameByYear[year] = last_name;
  }
  // std::string GetFullName(int year) {
  //
  //   std::string name = FindNameByYear(nameByYear,year);
  //   std::string surname = FindNameByYear(surnameByYear,year);
  //
  //   if (name.empty() && surname.empty()){
  //     return "Incognito";
  //   }else if(name.empty()){
  //     return surname + " with unknown first name";
  //   }else if(surname.empty()){
  //     return name + " with unknown last name";
  //   }
  //   return name + ' ' + surname;
  // }
  std::string GetFullNameWithHistory(int year) {

    std::string name = FindNameByYearHistory(nameByYear,year);
    std::string surname = FindNameByYearHistory(surnameByYear,year);

    if (name.empty() && surname.empty()){
      return "Incognito";
    }else if(name.empty()){
      return surname + " with unknown first name";
    }else if(surname.empty()){
      return name + " with unknown last name";
    }
    return name + ' ' + surname;
  }
private:
  std::map<int, std::string> nameByYear;
  std::map<int, std::string> surnameByYear;

};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  std::cout << person.GetFullNameWithHistory(1990) << std::endl;

  person.ChangeFirstName(1966, "Pauline");
  std::cout << person.GetFullNameWithHistory(1966) << std::endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  std::cout << person.GetFullNameWithHistory(1967) << std::endl;

  return 0;
}
