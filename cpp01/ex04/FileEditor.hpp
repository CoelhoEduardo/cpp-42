#ifndef FILEEDITOR_HPP
#define FILEEDITOR_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

class FileEditor {
public:
    FileEditor(const std::string& filename, const std::string& s1, const std::string& s2);
    ~FileEditor();

    void editFile();

private:
    std::string myReplace(const std::string& str, const std::string& from, const std::string& to);

    std::string _filename;
    std::string _s1;
    std::string _s2;
};

#endif
