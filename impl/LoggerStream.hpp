/*
 * Copyright by g3t0r1x. All rights reserved.
 */

#ifndef __SRC__LOGGER__IMPL__LOGGERSTREAM_HPP__
#define __SRC__LOGGER__IMPL__LOGGERSTREAM_HPP__

#include <iostream>

#include "LoggerSeverity.hpp"
#include "LoggerColors.hpp"

template <std::ostream& stream, class SeverityT>
class LoggerStream
{
public:
    ~LoggerStream()
    {
        stream << std::endl;
        RESET
    }

    template <class T>
    inline LoggerStream<stream, SeverityT>& operator<< (const T& message)
    {
        stream << message;
        return *this;
    };
};

#ifndef DBG_ENABLED
    template <std::ostream& stream>
    class LoggerStream<stream, Debug>
    {
    public:
        template <class T>
        inline LoggerStream<stream, Debug>& operator<< (const T& message)
        {
            return *this;
        };
    };
#endif

#endif // __SRC__LOGGER__IMPL__LOGGERSTREAM_HPP__
