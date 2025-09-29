#include <iostream>
#include <string>

// Simple test for string find functionality
int main() {
    std::string test = "This is SOS a test HELP";

    if (test.find("SOS") != std::string::npos) {
        std::cout << "✅ SOS found\n";
    } else {
        std::cout << "❌ SOS not found\n";
    }

    if (test.find("HELP") != std::string::npos) {
        std::cout << "✅ HELP found\n";
    } else {
        std::cout << "❌ HELP not found\n";
    }

    if (test.find("MISSING") == std::string::npos) {
        std::cout << "✅ MISSING correctly not found\n";
    } else {
        std::cout << "❌ MISSING unexpectedly found\n";
    }

    std::cout << "Test completed.\n";
    return 0;
}

// Compile: g++ test_communication.cpp -o test && ./test
