#ifndef DEBUG_DEFINES_HPP
#define DEBUG_DEFINES_HPP

#define SDL_CALL(debug, command) do { \
    if(!(command)) \
      debug->Error("Error: \"@3\" in @2, line: @1, file: @0", __FILE__, __LINE__, #command, SDL_GetError()); \
  } while(0)
  
#define GL_CALL(debug, command) do { \
    command; \
    while(GLenum error = glGetError()) \
      (debug)->Error("Error: @3 in @2, line: @1, file: @0", __FILE__, __LINE__, #command, Debug::GLErrorsNamesMap.at(error)); \
  } while(0)

#endif