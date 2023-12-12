
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
#include <sstream>

int main () {

    std::ifstream inFile;
    inFile.open("input.txt");

    if (inFile.is_open() == false) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    int idsum = 0;
    std::string line;
    bool ispossible = true;
    bool endgroup = false;
        
    while (std::getline(inFile, line)) {
        // std::cout << "\nSTART LINE" << std::endl;
        std::istringstream iss(line);
        std::string gameTag;

        int gamenum;
        char garb;
        int red_cube    = 0;
        int green_cube  = 0;
        int blue_cube   = 0;
        int count;
        std::string cube;

        iss >> gameTag >> gamenum >> garb;
        while (iss >> count >> cube) {

            // Process cube (red, green, blue)
            if (cube.back() == ',') {
                cube = cube.substr(0, cube.length() - 1);
            } else {
                if (cube.back() == ';') {
                    cube = cube.substr(0, cube.length() - 1);
                }
                endgroup = true;
            }

            if (cube == "red") {
                red_cube = count;
            } else if (cube == "green") {
                green_cube = count;
            } else if (cube == "blue") {
                blue_cube = count;
            }
            
            if (endgroup) {
                if (red_cube > 12 || green_cube > 13 || blue_cube > 14) {
                    ispossible = false;
                }
                red_cube = 0;
                green_cube = 0;
                blue_cube = 0;
                endgroup = false;
            }
        }

        if (ispossible) {
            idsum += gamenum;
        }

        // reset values
        ispossible = true;
    }

    std::cout << "\n sum of id's = " << idsum << std::endl;

    inFile.close();


    return 0;
}

// ans: 2176