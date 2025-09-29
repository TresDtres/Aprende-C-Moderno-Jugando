#include <iostream>
#include <string>
#include <regex>  // C++11 regex for advanced pattern matching

int main() {
    std::string inputLine;
    std::string decodedMessage = "";
    std::regex pattern(R"(\b(SOS|HELP|DISTRESS|COLONY|EMERGENCY)\b)", std::regex_constants::icase);  // Case-insensitive

    std::cout << "📡 Enter the encrypted message lines (end with empty line) - Bonus: Regex decoding:\n";

    while (std::getline(std::cin, inputLine)) {
        if (inputLine.empty()) break;

        // Use regex to find all matches
        std::sregex_iterator begin(inputLine.begin(), inputLine.end(), pattern);
        std::sregex_iterator end;

        for (std::sregex_iterator i = begin; i != end; ++i) {
            std::smatch match = *i;
            decodedMessage += match.str() + " ";
        }
    }

    if (!decodedMessage.empty()) {
        decodedMessage.pop_back();
    }

    std::cout << "\nDecoded Message: " << decodedMessage << std::endl;

    if (!decodedMessage.empty()) {
        std::cout << "✅ Advanced decoding successful! Bonus achievement unlocked.\n";
    } else {
        std::cout << "❌ No message found.\n";
    }

    return 0;
}
