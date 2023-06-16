#include "Debug.hpp"

#include "Header.hpp"

#include "Logger.hpp"

namespace Tolik
{
const std::unordered_map<GLenum, std::string> Debug::GLErrorsNamesMap =
{
	{ GL_NO_ERROR,                      "GL_NO_ERROR" },
	{ GL_INVALID_ENUM,                  "GL_INVALID_ENUM" },
	{ GL_INVALID_VALUE,                 "GL_INVALID_VALUE" },
	{ GL_INVALID_OPERATION,             "GL_INVALID_OPERATION"} ,
	{ GL_INVALID_FRAMEBUFFER_OPERATION, "GL_INVALID_FRAMEBUFFER_OPERATION" },
	{ GL_OUT_OF_MEMORY,                 "GL_OUT_OF_MEMORY" },
	{ GL_STACK_UNDERFLOW,               "GL_STACK_UNDERFLOW" },
	{ GL_STACK_OVERFLOW,                "GL_STACK_OVERFLOW" }
};

static Debug s_instancce = Debug();

Debug::Debug()
{
  AddLogger("main");

}

void Debug::AddLogger(const std::string &name, const Logger &logger)
{
	std::unordered_map<std::string, Logger>::iterator it = m_loggers.find(name);
	if(it == m_loggers.end())
	{
		GetLogger("main").Error("logger with name: \'@0\', already exists", name);
		return;
	}
	m_loggers.emplace_hint(it, logger);
}

const Logger &Debug::GetLogger(const std::string &name)
{
  std::unordered_map<std::string, Logger>::iterator it = m_loggers.find(name);
	if(it == m_loggers.end())
	{
		GetLogger("main").Error("No logger with name: \'@0\'", name);
		return m_loggers.at("main");
	}
	return it->second;
}
}