#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
#include <stack>
#include <regex>

using namespace std;

stack<int> find_numbers(string line) {
    stack<int> numbers;
    
    int pos = 0;
    while (pos < line.size()) {
        int current_number = 0;
        char c = line[pos];
        if (isdigit(c)) {
            current_number = c - '0';
        } else if (isalpha(c)) {
            switch (c) {
                case 'o':
                    if (line.substr(pos, 3) == "one") {
                        current_number = 1;
                        pos += 2;
                    } 
                    break;
                case 't':
                    if (line.substr(pos, 3) == "two") {
                        if (line.substr(pos+2, 3) == "one") {
                            current_number = 1;
                            pos += 4;
                        } else {
                            current_number = 2;
                            pos += 2;
                        }
                    } else if (line.substr(pos, 5) == "three") {
                        current_number = 3;
                        pos += 4;
                    }
                    break;
                case 'f':
                    if (line.substr(pos, 4) == "four") {
                        current_number = 4;
                        pos += 3;
                    } else if (line.substr(pos, 4) == "five") {
                        current_number = 5;
                        pos += 3;
                    }
                    break;
                case 's':
                    if (line.substr(pos, 3) == "six") {
                        current_number = 6;
                        pos += 2;
                    } else if (line.substr(pos, 5) == "seven") {
                        current_number = 7;
                        pos += 4;
                    }
                    break;
                case 'e':
                    if (line.substr(pos, 5) == "eight") {
                        current_number = 8;
                        pos += 4;
                    }
                    break;
                case 'n':
                    if (line.substr(pos, 4) == "nine") {
                        current_number = 9;
                        pos += 3;
                    }
                    break;
            }
        }

        if (current_number != 0) {
            numbers.push(current_number);
        }
        pos++;
    }
    
    return numbers;
}

int get_bottom(stack<int> numbers) {
    int num;
    while (numbers.size() > 1) {
        numbers.pop();
    }
    num = numbers.top();
    return num;
}

int main() {
    vector<int> cal_values;
    string line;
    int line_num = 1;
    int sum = 0;
    ifstream inFile("input.txt");

    while (getline(inFile, line)) {
        int first = -1;
        int second = -1;
        stack<int> numbers = find_numbers(line);

        if (!numbers.empty()) {
            first = get_bottom(numbers);
            second = numbers.top();

            int cal_value = (first * 10) + second;
            sum += cal_value;
            cal_values.push_back(cal_value);
            cout << "Line# " << line_num++ << " | first: " << first << " second: " << second << " cal_value: " << cal_value << endl;
        }
        numbers = stack<int>();  // Clear the stack
    }
    cout << sum << endl;

    return 0;
}
