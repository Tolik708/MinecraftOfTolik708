#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "Header.hpp"

namespace Tolik
{
class Debug;

enum class LogType : char
{
  Info = 0,
  Warning,
  Error
};

struct LoggerState
{
  LogType logTpye;
};

class Logger
{
  using PatternType = std::vector<std::pair<std::string, std::function<std::string(const LoggerState*)>>>;
  using PatterIdentifierType = std::unordered_map<char, std::function<std::string(const LoggerState*)>>;
public:
  Logger(const std::string &patternString);

  template<typename... Args> inline void Warning(const std::string &format, Args&&... args)
  { state.logTpye = LogType::Warning; LogInfo(m_pattern); LogMessage(format, args...); LogInfo(m_postPattern); }
  template<typename... Args> inline void Error  (const std::string &format, Args&&... args)
  { state.logTpye = LogType::Error; LogInfo(m_pattern); LogMessage(format, args...); LogInfo(m_postPattern); }
  template<typename... Args> inline void Info   (const std::string &format, Args&&... args)
  { state.logTpye = LogType::Info; LogInfo(m_pattern); LogMessage(format, args...); LogInfo(m_postPattern); }

private:
  void LogInfo(const PatternType &patern) const;

  template<typename... Args> void LogMessage(const std::string &format, Args&&... args) const;
  template<typename T, typename... Args> void Iterate(std::vector<std::string> &container, T &&t, Args&&... args) const;
  void inline Iterate(std::vector<std::string> &container) const {}
 
  template<typename T, typename... Args> void Print(T &&t, Args&&... args) const;
  void Print() const {}

  PatternType m_pattern;
  PatternType m_postPattern;

  LoggerState state;

  static std::ostringstream s_stream;
  static const std::unordered_map<LogType, std::string> s_logTypeNameMap;
  static const std::unordered_map<LogType, uint32_t> s_logTypeColorMap;
  static const PatterIdentifierType s_patternIdentifier;

  static std::string GetTimeString();
};
}

#endif

#include "Logger.tpp"