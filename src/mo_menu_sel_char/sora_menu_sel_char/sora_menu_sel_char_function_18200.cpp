#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_10_rodata_6A8;

struct Vec3f {
    float x;
    float y;
    float z;
};

void fn_10_1C97C(Vec3f* a, int b, int c, Vec3f* d);
}

extern "C" void fn_10_18200(void* arg0, int arg1, int arg2) {
    unsigned char* base = (unsigned char*)arg0;
    int r4 = arg1;
    int r5 = arg2;

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

    int r0;
    if (result == 1) {
        r0 = 0;
    } else {
        unsigned char* p = *(unsigned char**)(base + 0x1f4);
        if (p[0x5d0] != 0) {
            r0 = 2;
        } else {
            r0 = (*(int*)(p + 0x5cc) - 2) == 0;
        }
    }

    switch (r0) {
    case 1:
        r5 = *(int*)(base + 0x1d0);
        r4 = 2;
        break;
    case 2:
        r4 = 3;
        r5 = *(int*)(base + 0x1d0);
        break;
    }

    Vec3f local;
    local.z = lbl_10_rodata_6A8;
    local.y = lbl_10_rodata_6A8;
    local.x = lbl_10_rodata_6A8;
    fn_10_1C97C((Vec3f*)(base + 0x1fc), r4, r5, &local);
}
