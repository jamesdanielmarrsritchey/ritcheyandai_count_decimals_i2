#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 7 || (std::string(argv[1]) != "--min_decimal") || (std::string(argv[3]) != "--max_decimal") || (std::string(argv[5]) != "--file")) {
        std::cerr << "Usage: " << argv[0] << " --min_decimal <min_decimal> --max_decimal <max_decimal> --file <file>\n";
        return 1;
    }

    int min_decimal = std::stoi(argv[2]);
    int max_decimal = std::stoi(argv[4]);
    std::string filename = argv[6];
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    int count = 0;
    char byte;
    while (file.read(&byte, 1)) {
        unsigned char decimal = static_cast<unsigned char>(byte);
        if (decimal >= min_decimal && decimal <= max_decimal) {
            ++count;
        }
    }

    file.close();
    std::cout << count << '\n';
    return 0;
}