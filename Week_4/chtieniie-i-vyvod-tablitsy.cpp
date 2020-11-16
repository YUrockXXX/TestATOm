#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::ifstream input_Table("input.txt", std::ios::in);
    if (input_Table.is_open()) {
        // std::string line;
        int column = 0;
        int lines = 0;
        input_Table >> lines;
        input_Table >> column;

        for (int y = 0; y < lines; ++y)
        {
            for (int x = 0; x < column; ++x)
            {
                int temp = 0;
                input_Table >> temp;
                input_Table.ignore(1);
                std::cout << std::setw(10) << temp ;
                if (x != column - 1)
                {
                    std::cout << ' ';
                }
            }
            // std::cout << "\n";
            if (y != lines - 1)
            {
                std::cout << "\n";
            }
        }
        input_Table.close();
    }
    else {
        std::cerr << "Unable to open file\n";
    }

    return 0;
}
