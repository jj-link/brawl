#include <gm/gm_global.h>
#include <gf/gf_pad_system.h>
#pragma force_active on

static inline int mode(int state) {
    int result;
    if (state >= 0 && state < 4) result = 1; else result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc) result = 1; else result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r;
            if (state >= 0xc && state < 0x10) r = 1; else r = 0;
            result = 3;
            if (r != 0) result = 2;
        }
    }
    return result;
}

static inline int special(int state) {
    if (mode(state) == 0) goto no;
    if (mode(state) != 1) goto yes;
no:
    return 0;
yes:
    return 1;
}

static inline int allow(int state) {
    if (mode(state) == 1 || special(state) || state == 1)
        return 0;
    return 1;
}

extern "C" void fn_10_2834(void* arg0, int* arg1) {
    unsigned char* sel = (unsigned char*)g_GameGlobal->m_selCharData;
    arg1[0] = -1;
    arg1[1] = -1;
    arg1[2] = -1;
    arg1[3] = -1;
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    if (mode(state) == 1) {
        if (sel[0] != 0)
            arg1[0] = sel[0] - 1;
        else
            arg1[0] = 0;
        arg1[1] = sel[0x11b] - 1;
        return;
    }

    unsigned char* entry = sel;
    int* out = arg1;
    for (int i = 0; i < *(int*)((char*)arg0 + 0x648); ++i) {
        if (i == 0) {
            int st = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
            if (special(st)) {
                arg1[0] = sel[0] - 1;
                goto next;
            }
        }
        *out = entry[0xbf] - 1;
next:
        entry += 0x5c;
        ++out;
    }

    state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    if (allow(state)) {
        gfPadStatus status;
        int* p = arg1;
        int j;
        for (j = 0; j < 4 && j < *(int*)((char*)arg0 + 0x648); ++p, ++j) {
            g_gfPadSystem->getSysPadStatus(j, &status);
            if (status.m_error == 0)
                *p = j;
        }

        int target;
        int i;
        int k = 0;
        p = arg1;
        for (i = 0; i < *(int*)((char*)arg0 + 0x648) && k < 4; ++p, ++i) {
            if (*p < 0) {
                int found = 0;
                while (k < 4 && !found) {
                    int cnt = *(int*)((char*)arg0 + 0x648);
                    target = k + 4;
                    int n;
                    for (n = 0; n < cnt; ++n) {
                        if (arg1[n] == target)
                            break;
                    }
                    if (n >= cnt) {
                        g_gfPadSystem->getSysPadStatus(target, &status);
                        if (status.m_error == 0) {
                            *p = target;
                            found = 1;
                        }
                    }
                    ++k;
                }
            }
        }
    }
}
