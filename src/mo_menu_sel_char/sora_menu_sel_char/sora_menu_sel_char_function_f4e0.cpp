#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
int fn_10_99B8(void*);
int fn_800B5854(void*, int, int, int, int);
extern const unsigned char lbl_10_rodata_4F0[];
}

struct SelSelf {
    char pad[0x410];
    void* m_410;
};

extern "C" void fn_10_F4E0(SelSelf* self, int arg1) {
    int idx = 0;
    int state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
    int result;
    if (state >= 0 && state < 4) result = 1; else result = 0;
    if (result != 0) {
        result = 0;
    } else {
        if (state >= 4 && state < 0xc) result = 1; else result = 0;
        if (result != 0) {
            result = 1;
        } else {
            int r0_4;
            if (state >= 0xc && state < 0x10) r0_4 = 1; else r0_4 = 0;
            result = 3;
            if (r0_4 != 0) result = 2;
        }
    }
    if (result == 2 && fn_10_99B8(self) == 0) {
        idx = 1;
    }
    int v;
    if (arg1 == 0) {
        v = lbl_10_rodata_4F0[idx * 2];
    } else {
        v = (lbl_10_rodata_4F0 + idx * 2)[1];
    }
    fn_800B5854(self->m_410, v, 0x10, 0, 0);
}
