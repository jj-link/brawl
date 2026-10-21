#include <gm/gm_global.h>
#pragma force_active on

extern "C" {

struct ArgA {
    char pad[0x1f4];
    void* ptr;
};

struct ObjB {
    char pad[0x5cc];
    int f5cc;
    unsigned char f5d0;
};

int fn_10_15168(void* arg0) {
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
    if (result == 1)
        return 0;
    ObjB* p = (ObjB*)(((ArgA*)arg0)->ptr);
    if (p->f5d0 != 0)
        return 2;
    return p->f5cc - 2 == 0;
}
}
