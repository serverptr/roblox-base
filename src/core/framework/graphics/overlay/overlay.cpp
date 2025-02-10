#define IMGUI_DEFINE_MATH_OPERATORS

#include "overlay.hpp"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"
#include "imgui/TextEditor.h"
#include <dwmapi.h>
#include "../../../library/json/json.hpp"

#include "ckey/keybind.hpp"
#include "../overlay/XorStr/xorstr.hpp"
#include "../overlay/XorStr/json.hpp"

#include <filesystem>
#include <thread>
#include <bitset>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <unordered_set>

#ifdef min
#undef min
#endif
#include <stack>

#ifdef max
#undef max
#endif
#include <Psapi.h>

template<typename T>
T custom_clamp(T value, T min, T max) {
	return value < min ? min : (value > max ? max : value);
}

ID3D11Device* overlay::d3d11Device = nullptr;
ID3D11DeviceContext* overlay::d3d11DeviceContext = nullptr;
IDXGISwapChain* overlay::dxgiSwapChain = nullptr;
ID3D11RenderTargetView* overlay::d3d11RenderTargetView = nullptr;
std::vector<std::string> outputLines;
