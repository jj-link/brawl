#include <gf/gf_pad_system.h>
#include <gf/gf_homemenu.h>
#include <revolution/OS/OSInterrupt.h>
#include <string.h>

#pragma force_active on

extern float lbl_805A1528;

void gfPadSystem::updateLow() {
    BOOL enabled = OSDisableInterrupts();
    gfPadType::PadType type;
    gfPadError::PadError error;
    u32 i;
    gfPadStatus* out;
    gfPadStatus* pads = m_systemPads;
    int flag;
    u8* p;

    updateLowGC(pads);

    p = (u8*)g_gfHomeMenu;

    if (p != 0) {
        flag = 0;
        if (((p[0xB1] >> 4) & 1) || *(int*)(p + 0x9C) != 0) {
            flag = 1;
        }
        if (flag != 0) {
            gfPadStatus unused[20];
            u8* bytes = (u8*)unused;
            float zero = lbl_805A1528;
            *(int*)(bytes + 0x4D4) = 0;
            *(int*)(bytes + 0x10) = 0;
            *(int*)(bytes + 0x4C) = 0;
            *(int*)(bytes + 0x88) = 0;
            *(int*)(bytes + 0xC4) = 0;
            *(int*)(bytes + 0x100) = 0;
            bytes[0x171] = 0;
            bytes[0x1B0] = 0;
            bytes[0x1F3] = 0;
            bytes[0x232] = 0;
            bytes[0x275] = 0;
            bytes[0x2B4] = 0;
            bytes[0x2F7] = 0;
            bytes[0x336] = 0;
            *(float*)(bytes + 0x364) = zero;
            *(float*)(bytes + 0x3A0) = zero;
            *(float*)(bytes + 0x3DC) = zero;
            *(float*)(bytes + 0x418) = zero;
            *(float*)(bytes + 0x46C) = zero;
            *(float*)(bytes + 0x4A8) = zero;

            out = pads;
            for (i = 0; i < 8; i++) {
                error = out->m_error;
                type = out->m_controllerType;
                memset(out, 0, sizeof(gfPadStatus));
                out->m_error = error;
                out->m_controllerType = type;
                out++;
            }
        } else {
            goto wii;
        }
    } else {
    wii:
        updateLowWii(pads + 4);
    }

    m_padQueue->push(pads);
    memcpy(m_systemPads, pads, 0x200);
    OSRestoreInterrupts(enabled);
}
