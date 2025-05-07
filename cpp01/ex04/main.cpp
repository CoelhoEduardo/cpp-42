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

#include "FileEditor.hpp"

int main(int argc, char* argv[]) {
    // Ensure the correct number of arguments
    if (argc != 4) {
        std::cerr << "Usage: ./replace <filename> <string_to_replace> <replacement_string>" << std::endl;
        return 1;
    }

    // Parse command-line arguments
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Validate inputs
    if (filename.empty()) {
        std::cerr << "Error: Filename must not be empty." << std::endl;
        return 1;
    }
    if (s1.empty()) {
        std::cerr << "Error: String to replace (s1) must not be empty." << std::endl;
        return 1;
    }

    // Create FileEditor instance and perform the replacement
    FileEditor editor(filename, s1, s2);
    editor.editFile();

    return 0;
}
