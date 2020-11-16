#include <iostream>
#include <fstream>
#include <iomanip>

int main() {
    std::ifstream readfile("input.txt", std::ios::in);
    if (readfile.is_open()) {
        double value;
        std::setprecision(3);
        while (readfile >> value) {
            std::cout << setiosflags(std::ios::fixed);
            std::cout << std::setprecision(3) << value << '\n';
        }
        readfile.close();
    }
    else {
        std::cerr << "Unable to open file\n";
    }
    return 0;
}
