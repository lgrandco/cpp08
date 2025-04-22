#ifndef COLORS_HPP
#define COLORS_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

#define ANSI_COLOR_BLACK "\x1b[30m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_WHITE "\x1b[37m"

#define ANSI_COLOR_BRIGHT_BLACK "\x1b[90m"
#define ANSI_COLOR_BRIGHT_RED "\x1b[91m"
#define ANSI_COLOR_BRIGHT_GREEN "\x1b[92m"
#define ANSI_COLOR_BRIGHT_YELLOW "\x1b[93m"
#define ANSI_COLOR_BRIGHT_BLUE "\x1b[94m"
#define ANSI_COLOR_BRIGHT_MAGENTA "\x1b[95m"
#define ANSI_COLOR_BRIGHT_CYAN "\x1b[96m"
#define ANSI_COLOR_BRIGHT_WHITE "\x1b[97m"

#define ANSI_RESET "\x1b[0m"
#define ANSI_BOLD "\x1b[1m"
#define ANSI_ITALIC "\x1b[3m"
#define ANSI_UNDERLINE "\x1b[4m"
#define ANSI_REVERSE "\x1b[7m"
#define ANSI_COLOR_BLACK "\x1b[30m"

const static std::string colors[10] = {
    ANSI_COLOR_GREEN,
    ANSI_COLOR_YELLOW,
    ANSI_COLOR_BLUE,
    ANSI_COLOR_MAGENTA,
    ANSI_COLOR_CYAN,
    ANSI_COLOR_BRIGHT_GREEN,
    ANSI_COLOR_BRIGHT_YELLOW,
    ANSI_COLOR_BRIGHT_BLUE,
    ANSI_COLOR_BRIGHT_MAGENTA,
    ANSI_COLOR_BRIGHT_CYAN,
};

inline std::string get_color(std::ostream& os = std::cout, int bold = -1) {
    if (bold > 0 && isatty(STDOUT_FILENO)) os << ANSI_BOLD;
    static unsigned int state = static_cast<unsigned int>(std::time(NULL));
    state = state * 1103515245 + 12345;
    std::string color = colors[state % 6];
    if (isatty(STDOUT_FILENO)) os << color;
    return color;
}

inline int
print_color(std::string text, std::ostream& os = std::cout, bool endl = true, int bold = -1) {
    if (&os == &std::cerr) {
        if (bold == -1 && &os == &std::cerr && isatty(STDOUT_FILENO)) os << ANSI_BOLD;
        if (isatty(STDOUT_FILENO)) os << ANSI_COLOR_RED;
    } else get_color(os, bold);
    os << text;
    if (isatty(STDOUT_FILENO)) os << ANSI_RESET;
    if (endl) os << std::endl;
    return 1;
}

inline std::string print_sep() {
    std::string
        sep = "----------------------------------------------------------------------------";
    std::cout << get_color(std::cout, 1) << sep << ANSI_RESET << std::endl;
    return "";
}

// int print_color(std::string text, std::ostream& os = std::cout, bool endl = true, int bold = -1);
// std::string get_color(std::ostream& os = std::cout, int bold = -1);

#endif // !COLORS_HPP
