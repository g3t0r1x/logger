/*
 * Copyright by g3t0r1x. All rights reserved.
 */

#ifndef __SRC__LOGGER__IMPL__LOGGERCOLORS_HPP__
#define __SRC__LOGGER__IMPL__LOGGERCOLORS_HPP__

#ifdef __unix__

    #include <iostream>

    #define RED\
        std::cerr << "\x1B[31m";\
        std::cout << "\x1B[31m";
    #define YELLOW\
        std::cerr << "\x1B[33m";\
        std::cout << "\x1B[33m";
    #define GREEN\
        std::cerr << "\x1B[32m";\
        std::cout << "\x1B[32m";
    #define CYAN\
        std::cerr << "\x1B[96m";\
        std::cout << "\x1B[96m";
    #define RESET\
        std::cerr << "\x1B[37m";\
        std::cout << "\x1B[37m";

#elif defined(_WIN32) || defined(WIN32)

    #include<Windows.h>

    #define RED\
        SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 12);\
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);\
    #define YELLOW\
        SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 14);\
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);\
    #define GREEN\
        SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 2);\
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);\
    #define CYAN\
        SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 11);\
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);\
    #define RESET\
        SetConsoleTextAttribute(GetStdHandle(STD_ERROR_HANDLE), 3);\
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);\

#endif

#endif // __SRC__LOGGER__IMPL__LOGGERCOLORS_HPP__
