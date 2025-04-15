// src/intro/hello.cpp
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> msg {"Hello", "from", "VS Code", "and", "Ubuntu!"};

    for (const std::string& word : msg) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    std::cout << "Debugging is ready!" << std::endl; // 加一行用于打断点

    return 0;
}