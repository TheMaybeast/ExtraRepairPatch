#include "Utils/logger.hpp"
#include "Utils/ExtraRepairPatch.hpp"
#include "Utils/version.h"
#include "main.h"
#include <windows.h>

void Main(){
    while(true){
        WAIT(0);
    }
}

BOOL APIENTRY DllMain(HMODULE hInstance, DWORD reason, LPVOID lpReserved) {
    Log::SetFile(".\\ExtraRepairPatch.log");
    switch (reason) {
        case DLL_PROCESS_ATTACH:
            Log::Write(INFO, std::format("====== Loading ExtraRepairPatch v{}.{}.{} ======", VERSION));
            ExtraRepairPatch::Patch();
            scriptRegister(hInstance, Main);
            break;
        case DLL_PROCESS_DETACH:
            ExtraRepairPatch::Remove();
            Log::Write(INFO, std::format("====== Unloaded ExtraRepairPatch v{}.{}.{} ======", VERSION));
            scriptUnregister(hInstance);
            break;
        default:
            break;
    }
    return TRUE;
}