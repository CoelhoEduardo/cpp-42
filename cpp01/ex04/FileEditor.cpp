#include "FileEditor.hpp"

// Constructor
FileEditor::FileEditor(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2) {}

// Destructor
FileEditor::~FileEditor() {}

// Helper function to replace all occurrences of 'from' with 'to' in a string
std::string FileEditor::myReplace(const std::string& str, const std::string& from, const std::string& to) {
    if (from.empty()) {
        throw std::invalid_argument("String to replace (s1) must not be empty.");
    }

    std::string result;
    std::string::size_type start_pos = 0;
    std::string::size_type pos;

    while ((pos = str.find(from, start_pos)) != std::string::npos) {
        result.append(str, start_pos, pos - start_pos); // Append part of the string before the match
        result.append(to); // Append the replacement string
        start_pos = pos + from.length(); // Move past the replaced part
    }

    result.append(str, start_pos); // Append the rest of the string
    return result;
}

// Main function to edit the file
void FileEditor::editFile() {
    // Open the input file
    std::ifstream inputFile(_filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Unable to open input file: " << _filename << std::endl;
        return;
    }

    // Open the output file
    std::ofstream outputFile((_filename + ".replace").c_str());
    if (!outputFile) {
        std::cerr << "Error: Unable to create output file: " << _filename << ".replace" << std::endl;
        return;
    }

    // Read the input file line by line and process replacements
    std::string line;
    while (std::getline(inputFile, line)) {
        try {
            outputFile << myReplace(line, _s1, _s2) << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return;
        }
    }

    std::cout << "File has been edited successfully. Output: " << _filename << ".replace" << std::endl;
}
