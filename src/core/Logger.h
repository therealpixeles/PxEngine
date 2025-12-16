#pragma once

#include <mutex>
#include <string>
#include <iostream>

namespace px::core {

class Logger {
public:
    enum class Level { Trace, Info, Warn, Error, Critical };

    Logger();
    ~Logger() = default;

    void log(Level level, const std::string &message);
    void info(const std::string &message);
    void warn(const std::string &message);
    void error(const std::string &message);
    void critical(const std::string &message);

private:
    std::mutex mutex_;
    void write(Level level, const std::string &message);
    const char *level_to_string(Level level) const;
};

} // namespace px::core
