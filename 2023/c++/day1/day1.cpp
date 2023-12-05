#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int sum_values(vector <int> values) {
    int sum = 0;
    for (int i = 0; i < values.size(); i++) {
        sum += values[i];
    }
    return sum;
}

int main () {
    vector <int> cal_values;
    string line;
    ifstream inFile("input.txt");

    while (getline(inFile, line)) {
        bool firstfound = false;
        bool secondfound = false;
        int loc = 0;
        int first = -1;
        int second = -1;
        for (int i = 0; i < line.size(); i++){
            if (isdigit(line[i])) {
                if (!firstfound) {
                    first = line[i] - '0';
                    firstfound = true;
                } else {
                    loc = i;
                }
            }

            if (loc == 0) {
                second = first;
            } else {
                second = line[loc] - '0';
            }
        }
        int cal_value = (first * 10) + second;
        cal_values.push_back(cal_value);
        cout << "first: " << first << " second: " << second << " cal_value: " << cal_value << endl;
    }

    cout << sum_values(cal_values) << endl;

    return 0;
}

//ans: 54951

/// EOF ///
