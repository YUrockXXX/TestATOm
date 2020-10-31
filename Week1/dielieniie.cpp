#include <iostream>

int main(){
        int x1 = 0, x2 = 0;
        std::cin >> x1 >> x2;
        if (x2 == 0) {
                std::cout << "Impossible";
        }
        else{
                std::cout << x1/x2;
        }

        return 0;
}
