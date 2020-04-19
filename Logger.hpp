/*
 * Copyright by g3t0r1x. All rights reserved.
 */

#ifndef __SRC__LOGGER__LOGGER_HPP__
#define __SRC__LOGGER__LOGGER_HPP__

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

#include "impl/LoggerColors.hpp"
#include "impl/LoggerSeverity.hpp"
#include "impl/LoggerStream.hpp"

class Logger
{
public:
    Logger() = default;
    explicit Logger(const std::string& prefix)
    {
        prefix_ += "[" + prefix + "]";
    };

    inline LoggerStream<std::cout, Answer> operator<< (const Answer& answer) const
    {
        GREEN
        print<std::cout>(answer);
        return LoggerStream<std::cout, Answer>();
    };

    inline LoggerStream<std::cout, Info> operator<< (const Info& info) const
    {
        RESET
        print<std::cout>(info);
        return LoggerStream<std::cout, Info>();
    };

    inline LoggerStream<std::cout, Debug> operator<< (const Debug& debug) const
    {
        #ifndef DBG_ENABLED
            return LoggerStream<std::cout, Debug>();
        #else
            CYAN
            print<std::cout>(debug);
            return LoggerStream<std::cout, Debug>();
        #endif
    }

    inline LoggerStream<std::cout, Warning> operator<< (const Warning& warning) const
    {
        YELLOW
        print<std::cout>(warning);
        return LoggerStream<std::cout, Warning>();
    };

    inline LoggerStream<std::cerr, Error> operator<< (const Error& error) const
    {
        RED
        print<std::cerr>(error);
        return LoggerStream<std::cerr, Error>();
    };

    Logger(Logger const&) = delete;
    Logger& operator=(Logger const&) = delete;
    Logger(Logger&&) = delete;
    Logger& operator=(Logger&&) = delete;

private:
    template <std::ostream& stream, class SeverityT>
    inline void print(const SeverityT& severity) const
    {
        const auto now = std::chrono::system_clock::now();
        const auto now_c = std::chrono::system_clock::to_time_t(now);
        const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
        stream << "["
            << std::put_time(std::localtime(&now_c), "%F %T")
            << '.' << std::setfill('0') << std::setw(3) << ms.count()
            << "]"
            << prefix_ << severity;
    }

    std::string prefix_;
};

#endif // __SRC__LOGGER__LOGGER_HPP__
