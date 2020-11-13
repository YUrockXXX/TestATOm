#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

class SortedStrings {
public:
  void AddString(const std::string& s) {
    sortedStrings.push_back(s);
    std::sort(sortedStrings.begin(),sortedStrings.end());
  }
  
  std::vector<std::string> GetSortedStrings() {
    return sortedStrings;
  }
private:
  std::vector<std::string> sortedStrings ;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const std::string& s : strings.GetSortedStrings()) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
}

int main() {
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;
}
