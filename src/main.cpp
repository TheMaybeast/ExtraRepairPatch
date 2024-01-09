#include "Utils/logger.hpp"
#include "Utils/ExtraRepairPatch.hpp"
#include "Utils/version.h"
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hInstance, DWORD reason, LPVOID lpReserved) {
    Log::SetFile(".\\ExtraRepairPatch.log");
    switch (reason) {
        case DLL_PROCESS_ATTACH:
            Log::Write(INFO, std::format("====== Loading ExtraRepairPatch v{}.{}.{} ======", VERSION));
            ExtraRepairPatch::Patch();
            break;
        case DLL_PROCESS_DETACH:
            Log::Write(INFO, "====== Unloading ExtraRepairPatch ======");
            ExtraRepairPatch::Remove();
            break;
        default:
            break;
    }
    return TRUE;
}