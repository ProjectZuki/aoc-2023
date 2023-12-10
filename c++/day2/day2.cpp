
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
#include <sstream>

int main () {
    std::stack<std::vector<int>> games;

    std::ifstream inFile;
    inFile.open("sample.txt");
    std::string gamestr;
    int gamenum;
    char garb;
    int red_cube    = 0;
    int green_cube  = 0;
    int blue_cube   = 0;

    std::string cube;
    int count;
    std::string line;
    int idsum = 0;

    if (inFile.is_open() == false) {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    bool ispossible = false;
        
    while (std::getline(inFile, line)) {
        // std::cout << "\nSTART LINE" << std::endl;
        std::istringstream iss(line);
        std::string gameTag;
        bool endgroup = false;

        iss >> gameTag >> gamenum >> garb;
        while (iss >> count >> cube) {
            if (cube.back() == ',') {
                cube = cube.substr(0, cube.length() - 1);
            } else if (cube.back() == ';') {
                cube = cube.substr(0, cube.length() - 1);
                endgroup = true;
            }
            // std::cout << "cube = " << cube << " count = " << count << std::endl;
            // Process cube (red, green, blue)
            if (cube == "red") {
                red_cube += count;
            } else if (cube == "green") {
                green_cube += count;
            } else if (cube == "blue") {
                blue_cube += count;
            }

            if (endgroup) {
                
                // std::cout << "\nNEXT GROUP" << std::endl;
                if (red_cube <= 12 && green_cube <= 13 && blue_cube <= 14) {
                    idsum += gamenum;
                    ispossible = true;
                    std::cout << std::endl;
                }
                endgroup = false;
            }

            // std::cout << "NEXT GROUP" << std::endl;
        //     std::cout << "red: " << red_cube << std::endl;
        //     std::cout << "green: " << green_cube << std::endl;
        //     std::cout << "blue: " << blue_cube << std::endl << std::endl;
        }
        // total_red += red_cube;
        // total_green += green_cube;
        // total_blue += blue_cube;
        // std::cout << "Game #" << gamenum << std::endl;
        // std::cout << "Total red = " << red_cube << std::endl;
        // std::cout << "Total green = " << green_cube << std::endl;
        // std::cout << "Total blue = " << blue_cube << std::endl;

        // if (red_cube <= 12 && green_cube <= 13 && blue_cube <= 14) {
        //     std::cout << "Game #" << gamenum << " Possible\n";
        //     idsum += gamenum;
        //     std::cout << std::endl;
        // } else {
        // }

        red_cube = 0;
        green_cube = 0;
        blue_cube = 0;
    }

    std::cout << "idsum = " << idsum << std::endl;

    inFile.close();


    return 0;
}