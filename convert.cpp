/*
    convert.cpp

    Convert the string

    Note: The "@CONCERN" is for pedagogical purposes only
*/

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char* argv[]) {

    // requires conversion option and string
    // @CONCERN
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <option> <string>\n";
        return 1;
    }

    // conversion option
    // @CONCERN
    std::string option(argv[1]);

    // input string
    // @CONCERN
    std::string s = argv[2];

    // convert the string according to the option
    // @CONCERN
    // @CONCERN
    if (option == "--upper") {

        for (auto pc = s.begin(); pc != s.end(); ++pc)
            *pc = std::toupper(*pc);

    } else if (option == "--lower") {

        for (auto pc = s.begin(); pc != s.end(); ++pc)
            *pc = std::tolower(*pc);

    } else {

        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }

    // output converted string
    // @CONCERN
    for (auto pc = s.cbegin(); pc != s.cend(); ++pc)
        std::cout << *pc;
    std::cout << '\n';

    return 0;
}
