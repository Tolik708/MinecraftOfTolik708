#ifndef LOGGER_TPP
#define LOGGER_TPP

namespace Tolik
{
template<typename T, typename... Args> void Logger::Print(T &&t, Args&&... args) const
{
  std::cout << std::move(t);
  Print(args...);
}

template<typename T, typename... Args> void Logger::Iterate(std::vector<std::string> &container, T &&t, Args&&... args) const
{
  s_stream << std::move(t);
  container.push_back(s_stream.str());
  s_stream.str(std::string());
  Iterate(container, args...);
}


template<typename... Args> void Logger::LogMessage(const std::string &format, Args&&... args) const
{
  std::vector<std::string> convertedArguments;
  Iterate(convertedArguments, args...);

  std::size_t lastPosition = 0;
  std::size_t position = format.find('@', 0);

  if (position == std::string::npos)
  {
    Print(format, args...);
    return;
  }

  while (position != std::string::npos)
  {
    std::size_t numberLength = 0;
    while (isdigit(format[position + numberLength + 1])) numberLength++;
    if (numberLength == 0)
      continue;
    
    Print(format.substr(lastPosition, position - lastPosition));
    
    //we know that std::stoi won't fail because number length shows us that it is numbers
    int index = std::stoi(format.substr(position + 1, numberLength));
    if (index < static_cast<int>(convertedArguments.size()) && index >= 0)
      Print(convertedArguments[index]);
    
    lastPosition = position + numberLength + 1;
    position = format.find('@', lastPosition);
  }
}
}

#endif