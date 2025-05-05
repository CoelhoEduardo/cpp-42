/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecoelho- <ecoelho-@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:30:47 by ecoelho-          #+#    #+#             */
/*   Updated: 2025/05/05 17:32:32 by ecoelho-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

class FileEditor {
public:
    FileEditor(const std::string& filename, const std::string& s1, const std::string& s2)
        : _filename(filename), _s1(s1), _s2(s2) {}

    ~FileEditor() {}

    std::string myReplace(const std::string& str, const std::string& from, const std::string& to) {
        std::string result;
        std::string::size_type start_pos = 0;
        std::string::size_type pos;

        while ((pos = str.find(from, start_pos)) != std::string::npos) {
            result.append(str, start_pos, pos - start_pos);
            result.append(to);
            start_pos = pos + from.length();
        }
        result.append(str, start_pos);
        return result;
    }

    void editFile() {
        std::ifstream inputFile(_filename.c_str());
        if (!inputFile) {
            std::cerr << "Error: Unable to open input file." << std::endl;
            return;
        }

        std::ofstream outputFile((_filename + ".replace").c_str());
        if (!outputFile) {
            std::cerr << "Error: Unable to open output file." << std::endl;
            return;
        }

        std::string line;
        while (std::getline(inputFile, line)) {
            outputFile << myReplace(line, _s1, _s2) << std::endl;
        }

        std::cout << "File edited successfully." << std::endl;
    }

private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
};

int main() {
    std::string filename, s1, s2;

    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::cout << "Enter string to replace: ";
    std::cin >> s1;

    std::cout << "Enter replacement string: ";
    std::cin >> s2;

    if (filename.empty() || s1.empty()) {
        std::cerr << "Error: filename and s1 must not be empty." << std::endl;
        return 1;
    }

    FileEditor editor(filename, s1, s2);
    editor.editFile();

    return 0;
}
