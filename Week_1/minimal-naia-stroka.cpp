#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
        std::vector<std::string> v;
        for (int i = 0; i < 3; i++) {
                std::string str = "";
                std::cin >> str;
                v.push_back(str);
        }
        std::sort(v.begin(), v.end());
        std::cout << v[0];

        return 0;
}
