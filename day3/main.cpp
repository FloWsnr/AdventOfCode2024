#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

int main() {
    std::ifstream file("input.txt"); // Open the file
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string content = buffer.str();

    int num1, num2;
    int product;
    int sum = 0;
    // search for all the expressions mul(a,b)
    std::regex mul_regex("mul\\(([0-9]+),([0-9]+)\\)");
    std::smatch match;
    while (std::regex_search(content, match, mul_regex)) {

        num1 = std::stoi(match.str(1));
        num2 = std::stoi(match.str(2));

        product = num1 * num2;
        sum += product;

        // remove the match from the content
        content = match.suffix().str();
    }
    std::cout << "Sum of all products: " << sum << std::endl;
}
