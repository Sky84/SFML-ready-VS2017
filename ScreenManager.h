#pragma once
#include "Screen.h"
#include <map>
class ScreenManager
{
public:
	ScreenManager();

	std::map<std::string_view, Screen> screens;
};

