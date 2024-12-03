#include <iostream>
#include <fstream>
#include <string>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

// Recursive function to check if the numbers are in a monotonic decrease
bool check_monotonic_decrease(const std::vector<int>& numbers, int index) {
    // abort for last number
    if (index == numbers.size() - 1) { return true; }

    // check if current number is smaller than next number (than it would not be decreasing)
    if (numbers[index] <= numbers[index + 1]) {
        return false;
    }
    // addtional check for difference > 3
    if (abs(numbers[index] - numbers[index + 1]) > 3)
    {
        return false;
    }
    // recursive call
    return check_monotonic_decrease(numbers, index + 1);
}


bool check_monotonic_increase(const std::vector<int>& numbers, int index) {
    // abort for last number
    if (index == numbers.size() - 1) { return true; }

    int current = numbers[index];
    int next = numbers[index + 1];

    // check if current number is larger than next number
    if (current >= next) {
        return false;
    }
    // addtional check for difference > 3
    if (abs(current - next) > 3)
    {
        return false;
    }
    // recursive call
    return check_monotonic_increase(numbers, index + 1);
}


int main() {
    std::ifstream file("day2_input.txt"); // Open the file
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    int num_correct = 0;
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

        bool increase = check_monotonic_increase(numbers, 0);
        bool decrease = check_monotonic_decrease(numbers, 0);

        if (increase || decrease) {
            ++num_correct;
        }


    }
    std::cout << "Number of correct lines" << std::endl;
    std::cout << num_correct << std::endl;
    file.close(); // Close the file
    return 0;
}