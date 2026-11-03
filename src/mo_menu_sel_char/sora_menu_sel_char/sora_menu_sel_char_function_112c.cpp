#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
int fn_10_112C(void) {
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int result;
    if (state >= 0 && state < 4)
        result = 1;
    else
        result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc)
            result = 1;
        else
            result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r0_4;
            if (state >= 0xc && state < 0x10)
                r0_4 = 1;
            else
                r0_4 = 0;
            result = 3;
            if (r0_4 != 0)
                result = 2;
        }
    }
    if (result == 0)
        goto M;
    if (state >= 0 && state < 4)
        result = 1;
    else
        result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc)
            result = 1;
        else
            result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r0_5;
            if (state >= 0xc && state < 0x10)
                r0_5 = 1;
            else
                r0_5 = 0;
            result = 3;
            if (r0_5 != 0)
                result = 2;
        }
    }
    if (result != 1)
        goto L;
M:
    return 0;
L:
    return 1;
}
}