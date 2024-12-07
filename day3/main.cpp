#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string text = buffer.str();

    int sum = 0;
    bool enabled = true;  // mul instructions are enabled at the start

    // Match mul(X,Y), do(), and don't() instructions
    std::regex instruction_regex(R"((?:mul\((\d+),(\d+)\)|do\(\)|don't\(\)))");

    std::smatch match;
    std::string::const_iterator searchStart(text.cbegin());

    while (std::regex_search(searchStart, text.cend(), match, instruction_regex)) {
        if (match[0] == "do()") {
            enabled = true;
        }
        else if (match[0] == "don't()") {
            enabled = false;
        }
        else if (enabled && match[1].matched) { // This is a mul() instruction and multiplication is enabled
            int num1 = std::stoi(match[1]);
            int num2 = std::stoi(match[2]);
            sum += num1 * num2;
        }

        searchStart = match.suffix().first;
    }

    std::cout << "Sum of all enabled products: " << sum << std::endl;
    return 0;
}