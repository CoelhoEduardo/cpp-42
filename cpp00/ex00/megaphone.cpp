#include <ctype.h>
#include <iostream>

int main(int argc, char *argv[]) {

  if (argc > 1) {
    for (int index = 1; index < argc; index++) {
      char *str = argv[index];
      char current;

      for (int jndex = 0; (current = str[jndex]); jndex++)
        std::cout << (char)toupper(current);
    }

    std::cout << std::endl;
  } else {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  }

  return 0;
}
