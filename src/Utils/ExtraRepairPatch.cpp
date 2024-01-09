#include "ExtraRepairPatch.hpp"
#include "memory.hpp"
#include "logger.hpp"

bool ExtraRepairPatch::Patch() {
    if (m_Patched) return true;

    if (m_Location == 0) {
        uintptr_t addr = mem::FindPattern(m_Pattern);
        if (addr == 0) return false;
        m_Location = addr;
        Log::Write(INFO, std::format("ExtraRepairPatch @ {:X}", m_Location));
    }

    if (m_OriginalBytes == 0)
        m_OriginalBytes = *reinterpret_cast<uint32_t*>(m_Location + m_Offset);

    Log::Write(INFO, std::format("Original bytes: {:X}", m_OriginalBytes));

    *reinterpret_cast<uint32_t*>(m_Location + m_Offset) = 0;
    Log::Write(INFO, "ExtraRepairPatch applied successfully!");
    m_Patched = true;
    return true;
}

bool ExtraRepairPatch::Remove() {
    if (!m_Patched || m_OriginalBytes == 0) return false;

    *reinterpret_cast<uint32_t*>(m_Location + m_Offset) = m_OriginalBytes;
    Log::Write(INFO, "ExtraRepairPatch removed successfully!");
    m_Patched = false;
    return true;
}