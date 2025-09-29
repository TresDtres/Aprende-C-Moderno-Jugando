#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string inputLine;
    std::string decodedMessage = "";
    std::vector<std::string> keywords = {"SOS", "HELP", "DISTRESS", "COLONY", "EMERGENCY"};

    std::cout << "📡 Enter the encrypted message lines (end with empty line):\n";

    // Use std::getline to read input lines until empty
    while (std::getline(std::cin, inputLine)) {
        if (inputLine.empty()) break;

        // Search for each keyword in the line
        for (auto& keyword : keywords) {  // Using auto for type deduction (C++11, but modern)
            size_t pos = inputLine.find(keyword);
            if (pos != std::string::npos) {
                decodedMessage += keyword + " ";
                // Optional: Remove the keyword to avoid duplicates, but for simplicity, keep
            }
        }
    }

    // Trim trailing space
    if (!decodedMessage.empty()) {
        decodedMessage.pop_back();
    }

    std::cout << "\nDecoded Message: " << decodedMessage << std::endl;

    if (!decodedMessage.empty()) {
        std::cout << "✅ Message decoded successfully! The outpost is saved.\n";
    } else {
        std::cout << "❌ No message found. Try again.\n";
    }

    return 0;
}
