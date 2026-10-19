#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <types.h>
#include <string.h>
#pragma force_active on

struct fn_10_7618_Item {
    char _0[0x1DC];
    int m_firstPort;
    char _1[0x246];
    u8 m_hasSecondPort;
    char _2[5];
    int m_secondPort;
};

struct fn_10_7618_Self {
    char _0[0x44];
    fn_10_7618_Item* m_items[385];
    int m_itemCount;
};

extern "C" int fn_10_7618(fn_10_7618_Self* self) {
    u8 occupied[8];
    memset(occupied, 0, 8);

    fn_10_7618_Item* item;
    char* cursor = (char*)self;
    int i = 0;
    while (i < self->m_itemCount) {
        item = *(fn_10_7618_Item**)(cursor + 0x44);
        int port = item->m_firstPort;
        if (port >= 0)
            occupied[port] = 1;
        if (item->m_hasSecondPort)
            port = item->m_secondPort;
        else
            port = -1;
        if (port >= 0)
            occupied[port] = 1;
        cursor += 4;
        ++i;
    }

    gfPadStatus status;
    for (int pad = 0; pad < 8; ++pad) {
        if (occupied[pad] == 0) {
            g_gfPadSystem->getSysPadStatus(pad, &status);
            if (status.m_error == 0 &&
                (status.m_buttonsPressedThisFrame.bits & 0x1000) != 0)
                return pad;
        }
    }
    return -1;
}
