#include <types.h>
#pragma force_active on

extern "C" void fn_10_1D4A8(void* self);
extern "C" void fn_10_1CF64(void* self, u32 arg);

struct SelChar {
    u32 m_data[0x164 / 4];
    s32 m_164[4];
};

extern "C" int fn_10_1D3DC(void* self, s32 val) {
    SelChar* c = (SelChar*)self;
    for (int i = 0; i < 4; i++) {
        if (c->m_164[i] == val) {
            c->m_164[i] = -1;
            fn_10_1D4A8(self);
            fn_10_1CF64(self, c->m_data[0x44 / 4]);
            return 1;
        }
    }
    return 0;
}
