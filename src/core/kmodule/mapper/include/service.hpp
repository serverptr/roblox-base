#pragma once
#include <Windows.h>
#include <string>

#include "intel.hpp"

namespace service
{
	bool RegisterAndStart(const std::wstring& driver_path);
	bool StopAndRemove(const std::wstring& driver_name);
};