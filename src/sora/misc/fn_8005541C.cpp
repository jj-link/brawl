#include <gm/gm_global.h>

#pragma force_active on

extern "C" int fn_8005541C() {
    GameGlobal* g = g_GameGlobal;
    unsigned char* rule = (unsigned char*)g->m_setRule;
    signed char* mode = (signed char*)g->m_modeMelee;
    unsigned char* chars = (unsigned char*)g->m_selCharData;

    switch (rule[7]) {
    default:
    case 0:
        mode[0] = -1;
        return 0;

    case 1:
        mode[0] = -1;
        return 1;

    case 2: {
        int index = mode[0];
        int found = 0;
        if (index == -1) {
            index = 0;
        } else {
            index = index + 1;
        }

        for (int i = 0; i != 4; i++) {
            int n = (index + i) % 4;
            if (chars[n * 0x5c + 0xb9] == 0) {
                index = n;
                found = 1;
                break;
            }
        }

        if (!found) {
            index = -1;
        }
        mode[0] = index;
        return 0;
    }

    case 3:
        mode[0] = -1;
        return 2;

    case 4: {
        signed char n = mode[2];
        int index = -1;
        if (n != -1) {
            unsigned char* row = chars + n * 0x5c;
            if (row[0xb9] == 0) {
                index = n;
            }
        }
        mode[0] = index;
        return 0;
    }
    }
}
