#include <gf/gf_pad_system.h>
#pragma force_active on
#define CLEAR(p) do { (p).m_buttonsPressedThisFrame2.bits = 0; (p).m_buttonsReleasedThisFrame.bits = 0; (p).m_buttonsPressedThisFrame.bits = 0; } while (0)
void gfPadSystem::clearPadEdgeRepert() {
    for (int i = 0; i < 8; ++i) {
        CLEAR(m_systemPads[i]);
        CLEAR(m_debugGcnPads[i]);
        CLEAR(m_menuGcnPads[i]);
    }
    CLEAR(m_sysPadMerged);
    CLEAR(m_menuPadMerged);
    CLEAR(m_debugPadMerged);
}
