#include <iostream>
#include <fstream>

int main() {
    std::ifstream readfile("input.txt", std::ios::in);
    if (readfile.is_open()) {
        std::string line;
        while (std::getline(readfile, line)) {
            std::cout << line << '\n';
        }
        readfile.close();
    }
    else {
        std::cerr << "Unable to open file\n";
    }
    return 0;
}
