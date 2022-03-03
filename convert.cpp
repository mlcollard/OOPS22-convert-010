/*
    convert.cpp

    Convert the string

    Note: The "@CONCERN" is for pedagogical purposes only
*/

#include <iostream>
#include <string>
#include <cctype>

// applies the function to each part of the string
// @CONCERN s, traversal, myforeach(), apply()
void myforeach(std::string::const_iterator begin, std::string::const_iterator end,
    void (*apply)(char c)) {

    for (auto pc = begin; pc != end; ++pc)
        apply(*pc);
    std::cout << '\n';
}

// @CONCERN apply(), output_format
void output(char c) {
    std::cout << c;
}

int main(int argc, char* argv[]) {

    // requires conversion option and string
    // @CONCERN argc, argv, argv[0], error handling
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <option> <string>\n";
        return 1;
    }

    // conversion option
    // @CONCERN argc == 3, argv, argv[1] is option, option
    std::string option(argv[1]);

    // input string
    // @CONCERN argc == 3, argv, argv[2] is string, string
    std::string s = argv[2];

    // convert the string according to the option
    // @CONCERN "--upper", "--lower", invalid options, error handling
    // @CONCERN s, traversal, ctype
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
    // @CONCERN s, myforeach(), output()
    myforeach(s.cbegin(), s.cend(), output);

    return 0;
}
