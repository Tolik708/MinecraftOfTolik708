#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "Header.hpp"

#define SDL_CALL(debug, command) do { \
    if(!(command)) \
      debug->Error("Error: \"@3\" in @2, line: @1, file: @0", __FILE__, __LINE__, #command, SDL_GetError()); \
  } while(0)
  
#define GL_CALL(debug, command) do { \
    command; \
    while(GLenum error = glGetError()) \
      debug->Error("Error: @3 in @2, line: @1, file: @0", __FILE__, __LINE__, #command, Debug::GLErrorsNamesMap.at(error)); \
  } while(0)

namespace Tolik
{
enum class LogType
{
  Debug = 0,
  Info,
  Warning,
  Error
};

class Debug
{
public:
  using PaternType = std::vector<std::pair<std::string, std::function<void(void)>>>;
  
  static const std::unordered_map<GLenum, std::string> GLErrorsNamesMap;

  Debug();

  template<typename... Args> inline void Log    (const std::string &format, Args&&... args) { m_logType = LogType::Debug;   LogInfo(m_patern); LogMessage(format, args...); LogInfo(m_postPatern); }
  template<typename... Args> inline void Warning(const std::string &format, Args&&... args) { m_logType = LogType::Warning; LogInfo(m_patern); LogMessage(format, args...); LogInfo(m_postPatern); }
  template<typename... Args> inline void Error  (const std::string &format, Args&&... args) { m_logType = LogType::Error;   LogInfo(m_patern); LogMessage(format, args...); LogInfo(m_postPatern); }
  template<typename... Args> inline void Info   (const std::string &format, Args&&... args) { m_logType = LogType::Info;    LogInfo(m_patern); LogMessage(format, args...); LogInfo(m_postPatern); }

  void SetPattern(const std::string &newPatern);
  void ResetPattern();
private:
  void LogInfo(const PaternType &patern);
  inline void PrintTime();

  template<typename... Args> void LogMessage(const std::string &format, Args&&... args);
  template<typename T, typename... Args> void Iterate(std::vector<std::string> &container, T &&t, Args&&... args);
  void inline Iterate(std::vector<std::string> &container) {}
 
  template<typename T, typename... Args> void Print(T &&t, Args&&... args);
  void Print() {}


  LogType m_currentLogType = LogType::Debug;
  LogType m_logType = LogType::Debug;
  HANDLE m_hConsole;
  std::ostringstream m_stream;
  PaternType m_patern;
  PaternType m_postPatern;
  const std::unordered_map<char, std::function<void(void)>> m_paternIdentifier;

  
  static const std::unordered_map<LogType, std::string> LogTypeNameMap;
  static const std::unordered_map<LogType, uint32_t> LogTypeColorMap;
};

// template functions

template<typename T, typename... Args> void Debug::Print(T &&t, Args&&... args)
{
  std::cout << std::move(t);
  Print(args...);
}

template<typename T, typename... Args> void Debug::Iterate(std::vector<std::string> &container, T &&t, Args&&... args)
{
  m_stream << std::move(t);
  container.push_back(m_stream.str());
  m_stream.str(std::string());
  Iterate(container, args...);
}


template<typename... Args> void Debug::LogMessage(const std::string &format, Args&&... args)
{
  std::vector<std::string> convertedArguments;
  Iterate(convertedArguments, args...);

  uint32_t lastPos = 0;
  uint32_t position = format.find('@', 0);

  if (position == std::string::npos)
  {
    Print(format, args...);
    return;
  }

  for (; position != std::string::npos; position++, position = format.find('@', position))
  {
    uint32_t numberLength = 0;
    while (isdigit(format[position + numberLength + 1])) numberLength++;
    if (numberLength == 0)
      continue;
    
    Print(format.substr(lastPos, position - lastPos));
    
    //we know that std::stoi won't fail because number length shows us that it is numbers
    int index = std::stoi(format.substr(position + 1, numberLength));
    if (index < static_cast<int>(convertedArguments.size()) && index >= 0)
      Print(convertedArguments[index]);
    
    lastPos = position + numberLength + 1;
  }
}
}

#endif