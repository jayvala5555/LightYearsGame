#pragma once

#include <string>

std::string getResourceDir()
{
#ifdef NDEBUG // release build
    return "assets/";
#else
    return "/home/jay/Cpp_Game/LightYears/LightYearsGame/assets/";
#endif
}
