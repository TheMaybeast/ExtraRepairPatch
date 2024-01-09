// Memory utility by ikt32
// https://github.com/ikt32/GTAVManualTransmission/blob/9618fcac98fae0d6e72aacba71fbf898177a8cb5/Gears/Memory/NativeMemory.hpp

#pragma once
#include <cstdint>
#include <vector>

namespace mem {
	uintptr_t FindPattern(const char* pattStr);
}