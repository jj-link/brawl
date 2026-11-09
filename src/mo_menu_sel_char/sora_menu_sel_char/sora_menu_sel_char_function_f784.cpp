#include <gm/gm_global.h>
#pragma force_active on

struct SelSelf {
    char pad0[0x414];
    void* m_414;
    char pad1[0x5c4 - 0x418];
    void* m_5c4;
};

extern "C" {
void printIndex__5MuMsgFUlUlPv(void* msg, unsigned long a, unsigned long b, void* c);
int fn_10_99B8(void*);
int fn_800B5854(void*, int, int, int, int);
extern const int lbl_10_rodata_4F8[];
}

extern "C" void fn_10_F784(SelSelf* self, int arg1) {
    int idx = 0;
    printIndex__5MuMsgFUlUlPv(self->m_5c4, 1, lbl_10_rodata_4F8[arg1], 0);
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
        idx = 4;
    }
    fn_800B5854(self->m_414, idx, 0x10, 0, 0);
}
