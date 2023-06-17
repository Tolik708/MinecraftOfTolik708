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

const Logger::PatterIdentifierType Logger::s_patternIdentifier =
{
	std::make_pair('T', [](const LoggerState *state) -> std::string { return GetTimeString(); })
};

std::ostringstream Logger::s_stream = std::ostringstream();

Logger::Logger(const std::string &patternString)
{
  PatternType *currentPattern = &m_pattern;
	uint32_t patternIndex = 0;
	bool message = false;

	currentPattern->emplace_back();
	for (std::size_t stringPos = 0; stringPos < patternString.length(); stringPos++)
	{
		if (patternString[stringPos] == '@')
		{
			if (stringPos + 1 >= patternString.length())
			{
				(*currentPattern)[patternIndex].first += patternString[stringPos];
				break;
			}

			if(patternString[stringPos + 1] == 'M' && !message)
			{
				currentPattern = &m_postPattern;
				currentPattern->emplace_back();
				patternIndex = 0;
				stringPos++;
				message = true;
				continue;
			}

			PatterIdentifierType::const_iterator it = s_patternIdentifier.find(patternString[stringPos + 1]);
			if (it != s_patternIdentifier.end())
			{
				(*currentPattern)[patternIndex].second = it->second;
				currentPattern->emplace_back();
				patternIndex++;
				stringPos++;
				continue;
			}
		}
		(*currentPattern)[patternIndex].first += patternString[stringPos];
	}
}

void Logger::LogInfo(const PatternType &pattern) const
{
	for (std::size_t i = 0; i < pattern.size(); i++)
	{
		Print(pattern[i].first);
		if (pattern[i].second != nullptr)
			Print(pattern[i].second(&state));
	}
}

std::string Logger::GetTimeString()
{
	std::time_t seconds = time(NULL);
	std::tm *buf = localtime(&seconds);
	return std::string(std::put_time(buf, "%H:%M:%S")._M_fmt);
}
}
