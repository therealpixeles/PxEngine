#include "Logger.h"

#include <chrono>
#include <iomanip>

namespace px::core {

Logger::Logger() = default;

void Logger::log(Level level, const std::string &message) { write(level, message); }
void Logger::info(const std::string &message) { write(Level::Info, message); }
void Logger::warn(const std::string &message) { write(Level::Warn, message); }
void Logger::error(const std::string &message) { write(Level::Error, message); }
void Logger::critical(const std::string &message) { write(Level::Critical, message); }

void Logger::write(Level level, const std::string &message) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::tm tm{};
#if defined(_WIN32)
    localtime_s(&tm, &time);
#else
    localtime_r(&time, &tm);
#endif
    std::clog << "[" << std::put_time(&tm, "%F %T") << "] " << level_to_string(level) << ": " << message
              << std::endl;
}

const char *Logger::level_to_string(Level level) const {
    switch (level) {
    case Level::Trace:
        return "TRACE";
    case Level::Info:
        return "INFO";
    case Level::Warn:
        return "WARN";
    case Level::Error:
        return "ERROR";
    case Level::Critical:
        return "CRITICAL";
    }
    return "UNKNOWN";
}

} // namespace px::core
