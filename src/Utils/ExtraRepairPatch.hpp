#include <cstdint>

/// This patch replaces the bytes corresponding to a call to CVehicle::Fix() when you disable an
/// extra.

class ExtraRepairPatch {
public:
    static bool Patch();
    static bool Remove();

    static bool IsPatched() { return m_Patched; }

private:
    inline static bool m_Patched = false;

    inline static uintptr_t m_Location = 0;
    inline static uint32_t m_OriginalBytes = 0;

    inline static const char* m_Pattern = "48 8B CB ?? ?? ?? ?? 00 00 48 8B ?? ?? 8B 81 ?? ?? 00 00";
    inline static const int32_t m_Offset = 3;
};