/*
 * Copyright by g3t0r1x. All rights reserved.
 */

#ifndef __SRC__LOGGER__IMPL__LOGGERSEVERITY_HPP__
#define __SRC__LOGGER__IMPL__LOGGERSEVERITY_HPP__

#include <iostream>

static const struct Answer{} answer;
inline std::ostream& operator<<(std::ostream& os, const Answer& answer)
{
    return (os << "[ANS] ");
};

static const struct Info{} info;
inline std::ostream& operator<<(std::ostream& os, const Info& info)
{
    return (os << "[INF] ");
};

static const struct Debug{} debug;
inline std::ostream& operator<<(std::ostream& os, const Debug& debug)
{
    return (os << "[DBG] ");
};

static const struct Warning{} warning;
inline std::ostream& operator<<(std::ostream& os, const Warning& warning)
{
    return (os << "[WRN] ");
};

static const struct Error{} error;
inline std::ostream& operator<<(std::ostream& os, const Error& error)
{
    return (os << "[ERR] ");
};

#endif // __SRC__LOGGER__IMPL__LOGGERSEVERITY_HPP__
