#include <iostream>
#include <string>

int main() {
    std::string inputLine;
    std::string decodedMessage = "";

    std::cout << "📡 Enter the encrypted message lines (end with empty line):\n";

    // TODO: Use std::getline to read input lines until empty
    // For each line, search for keywords like "SOS", "HELP", etc.
    // Append found keywords to decodedMessage
    // Hint: Use find() or substr() for searching

    while (std::getline(std::cin, inputLine)) {
        if (inputLine.empty()) break;
        // TODO: Implement search logic here
        // Example: if (inputLine.find("SOS") != std::string::npos) {
        //     decodedMessage += "SOS ";
        // }
    }

    std::cout << "\nDecoded Message: " << decodedMessage << std::endl;

    if (!decodedMessage.empty()) {
        std::cout << "✅ Message decoded successfully!\n";
    } else {
        std::cout << "❌ No message found. Try again.\n";
    }

    return 0;
}
