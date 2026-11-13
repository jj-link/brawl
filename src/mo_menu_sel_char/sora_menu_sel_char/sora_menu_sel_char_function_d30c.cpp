#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

struct SelCharState {
    char pad[0x5d4];
    s32 m_5d4;
    s32 m_5d8;
    s32 m_5dc;
};

extern "C" {
int fn_10_99B8(void*);
void fn_10_4CAC(SelCharState*, s32, u32);
void fn_10_CEEC(SelCharState*, s32);
}

static inline void updateIndex(s32 index, SelCharState* self) {
    fn_10_CEEC(self, index);
}

extern "C" void fn_10_D30C(SelCharState* arg) {
        int state2;
    s32 idx;
    SelCharState* self = arg;

    if (self->m_5d4 == 1) {
        int state;
        int result;
        s32 v;

        v = self->m_5dc - 1;
        if (v < 1)
            v = 0x63;
        idx = v;
        self->m_5dc = idx;

        state = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
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

        if (result == 2) {
            if (fn_10_99B8(self) != 0)
                fn_10_4CAC(self, 0, 1);
        }
    } else {
        int flag;
        int state1 = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
        s32 v;

        switch (state1) {
        case 1:
        case 0x12:
            flag = 1;
            break;
        default:
            flag = 0;
            break;
        }

        v = self->m_5d8 - 1;
        if (v < flag) {
            v = 0x63;
            if (state1 == 0x12)
                v = 0x3c;
        }
        idx = v;
        self->m_5d8 = idx;

        state2 = ((unsigned char*)g_GameGlobal->m_selCharData)[4];
        int result;
        if (state2 >= 0 && state2 < 4)
            result = 1;
        else
            result = 0;

        if (result != 0) {
            result = 0;
        } else {
            if (state2 >= 4 && state2 < 0xc)
                result = 1;
            else
                result = 0;

            if (result != 0) {
                result = 1;
            } else {
                int r0_4;
                if (state2 >= 0xc && state2 < 0x10)
                    r0_4 = 1;
                else
                    r0_4 = 0;
                result = 3;
                if (r0_4 != 0)
                    result = 2;
            }
        }

        if (result == 2) {
            if (fn_10_99B8(self) != 0)
                fn_10_4CAC(self, 0, 1);
        }
    }

    updateIndex(idx, self);
}
