#include <iostream>
#include <fstream>

int main() {


    std::ifstream readfile("input.txt", std::ios::in);
    if (readfile.is_open()) {
        std::string line;
        std::ofstream writeFile("output.txt", std::ios::out);
        if (writeFile.is_open()) {
            while (std::getline(readfile, line)) {
                writeFile << line << '\n';
            }
            writeFile.close();
        }
        else {
            std::cerr << "Unable to open file\n";
        }

        readfile.close();
    }
    else {
        std::cerr << "Unable to open file\n";
    }
    return 0;
}
