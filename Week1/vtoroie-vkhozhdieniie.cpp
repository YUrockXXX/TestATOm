#include <iostream>
#include <string>
#include <algorithm>

int main(){
        std::string str = "";
        std::cin >> str;

        int num_items1 = std::count(std::begin(str), std::end(str), 'f');
        if (num_items1 == 0) {
                std::cout << -2;
        }
        else if (num_items1 == 1) {
                std::cout << -1;
        }
        else{
                auto result1 = std::find(std::begin(str), std::end(str), 'f');
                auto result2 = std::find(result1+1, std::end(str), 'f');
                std::cout << result2 - std::begin(str);
        }

        return 0;
}
