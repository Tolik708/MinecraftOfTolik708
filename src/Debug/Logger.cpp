#include "Logger.hpp"

#include "Header.hpp"

#include "Debug.hpp"

namespace Tolik
{
const std::unordered_map<LogType, std::string> Logger::s_logTypeNameMap = 
{
  { LogType::Info,    "INFO" },
  { LogType::Warning, "WARNING" },
  { LogType::Error,   "ERROR" }
};
const std::unordered_map<LogType, uint32_t> Logger::s_logTypeColorMap = 
{
  { LogType::Info,    8 },
  { LogType::Warning, 14 },
  { LogType::Error,   12 }
};
const std::unordered_map<char, std::function<std::string(const LoggerState&)>> Logger::s_patternIdentifier =
{
  { 'T', [](const LoggerState& state) -> std::string { return GetTimeString(); } }
};

Logger::Logger(Debug *debug, const std::string &name, const std::string &newPattern)
{
  debug->AddLogger(name, this);

  PatternType *pattern = &m_pattern;
	uint32_t patternIndex = 0;
	bool message = false;

	pattern->clear();
	pattern->emplace_back();
	for (std::size_t stringPos = 0; stringPos < newPattern.length(); stringPos++)
	{
		if (newPattern[stringPos] == '@')
		{
			if (stringPos + 1 >= newPattern.length())
			{
				(*pattern)[patternIndex].first += newPattern[stringPos];
				break;
			}

			if(newPattern[stringPos + 1] == 'M' && !message)
			{
				pattern = &m_postPattern;
				pattern->clear();
				pattern->emplace_back();
				patternIndex = 0;
				stringPos++;
				message = true;
				continue;
			}

			PatterIdentifierType::const_iterator it = s_patternIdentifier.find(newPattern[stringPos + 1]);
			if (it != s_patternIdentifier.end())
			{
				(*pattern)[patternIndex].second = it->second;
				pattern->emplace_back();
				patternIndex++;
				stringPos++;
				continue;
			}
		}
		(*pattern)[patternIndex].first += newPattern[stringPos];
	}
}

void Logger::LogInfo(const PatternType &pattern) const
{
	for (std::size_t i = 0; i < pattern.size(); i++)
	{
		Print(pattern[i].first);
		if (pattern[i].second != nullptr)
			Print(pattern[i].second(state));
	}
}

std::string Logger::GetTimeString()
{
	std::time_t seconds = time(NULL);
	std::tm *buf = localtime(&seconds);
	return std::string(std::put_time(buf, "%H:%M:%S")._M_fmt);
}
}
