#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>


bool check_safe(const std::vector<int>& numbers) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 0; i < numbers.size() - 1; ++i) {
        int diff = abs(numbers[i] - numbers[i + 1]);
        if (diff > 3 || diff < 1) {
            return false;
        }

        if (numbers[i] > numbers[i + 1]) {
            increasing = false;
        }
        if (numbers[i] < numbers[i + 1]) {
            decreasing = false;
        }
    }
    return increasing || decreasing;
}

bool check_safe_part2(const std::vector<int>& numbers) {
    if (check_safe(numbers)) {
        return true;
    }
    for (int i = 0; i < numbers.size(); ++i) {
        std::vector<int> new_numbers = numbers;
        new_numbers.erase(new_numbers.begin() + i);
        if (check_safe(new_numbers)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream file("day2_input.txt"); // Open the file
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    int num_correct = 0;
    bool safe;
    while (std::getline(file, line)) { // Read the file line by line

        // convert line into array of ints
        std::istringstream iss(line);
        std::string item;
        std::vector<int> numbers;
        int number;

        while (std::getline(iss, item, ' ')) {
            // convert item into int
            number = std::stoi(item);
            numbers.push_back(number);
        }

        // safe = check_safe(numbers);
        safe = check_safe_part2(numbers);
        if (safe) {
            num_correct++;
        }


    }
    std::cout << "Number of correct lines" << std::endl;
    std::cout << num_correct << std::endl;
    file.close(); // Close the file
    // test_main();
    return 0;
}