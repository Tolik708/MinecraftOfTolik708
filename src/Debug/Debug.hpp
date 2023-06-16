#ifndef DEBUG_HPP
#define DEBUG_HPP

#include "Header.hpp"

#include "Logger.hpp"

namespace Tolik
{
class Debug
{
public:
  Debug();
  static const Debug &Get() { return s_instance; }

  void AddLogger(const std::string &name, const Logger &logger);
  const Logger &GetLogger(const std::string &name);

  static const std::unordered_map<GLenum, std::string> GLErrorsNamesMap;

private:
  std::unordered_map<std::string, Logger> m_loggers;
  
  static Debug s_instance;
};
}

#endif