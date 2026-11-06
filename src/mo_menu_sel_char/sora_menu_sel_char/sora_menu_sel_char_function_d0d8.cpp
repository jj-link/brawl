#include <gm/gm_global.h>
#pragma force_active on

struct SelCharState {
    char pad000[0x5d4];
    s32 m_5d4;
    s32 m_5d8;
    s32 m_5dc;
};

extern "C" {
int fn_10_99B8(void* self);
void fn_10_4CAC(SelCharState* self, s32 a, u32 b);
void fn_10_CEEC(SelCharState* self, s32 v);
}

extern "C" void fn_10_D0D8(SelCharState* self) {
    s32 idx;

    if (self->m_5d4 == 1) {
        int state;
        int result;
        s32 v;
        v = self->m_5dc + 1;
        if (v > 0x63) {
            v = 1;
        }
        self->m_5dc = v;
        idx = v;

        state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
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
        if (result == 2) {
            if (fn_10_99B8(self) != 0) {
                fn_10_4CAC(self, 0, 1);
            }
        }
    } else {
        int state;
        int result;
        int limit;
        int st;
        s32 v;
        limit = 0x63;
        st = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
        if (st == 0x12) limit = 0x3c;
        v = self->m_5d8 + 1;
        if (v > limit) {
            switch (st) {
            case 1:
            case 0x12:
                v = 1;
                break;
            default:
                v = 0;
                break;
            }
        }
        self->m_5d8 = v;
        idx = v;

        state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
        if (state >= 0 && state < 4) result = 1; else result = 0;
        if (result != 0) {
            result = 0;
        } else {
            if (state >= 4 && state < 0xc) result = 1; else result = 0;
            if (result != 0) {
                result = 1;
            } else {
                int r0_5;
                if (state >= 0xc && state < 0x10) r0_5 = 1; else r0_5 = 0;
                result = 3;
                if (r0_5 != 0) result = 2;
            }
        }
        if (result == 2) {
            if (fn_10_99B8(self) != 0) {
                fn_10_4CAC(self, 0, 1);
            }
        }
    }
    fn_10_CEEC(self, idx);
}
