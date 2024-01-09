// Logging utility by ikt32
// https://github.com/ikt32/GTAVManualTransmission/blob/adb5bdb190c436f2e150eda5dc1fd21570228a60/Gears/Util/Logger.cpp

#pragma once
#include <format>
#include <string>
#include <vector>

enum LogLevel {
    DEBUG,
    INFO,
    WARN,
    ERR,
    FATAL,
};

class Log {
public:
    static void SetFile(const std::string& fileName);

    static void Clear();
    static void Write(LogLevel level, const std::string& text);

    template <typename... Args>
    static void Write(LogLevel level, const std::string& fmt, Args &&...args) {
        Write(level, std::vformat(fmt, std::make_format_args(std::forward<Args>(args)...)));
    }

private:
    static std::string getLevelText(LogLevel level);

    static std::string mFile;
    static LogLevel mMinLevel;
};