#include <types.h>
#pragma force_active on

struct ftManager;
extern "C" {
extern ftManager* g_ftManager;
extern void* g_aiMgr;
s32 getEntryId__9ftManagerFi(ftManager*, s32);
void fn_27_10A274(ftManager*, s32, s32);
void fn_27_10A320(ftManager*, s32, u8);
void fn_27_1F1B68(void*, s32, u8);
}

struct Self {
    u8 pad0[0x44];
    u8* data;
    u8 pad48[0xBC];
    s32 count;
};

extern "C" void fn_27_24D198(Self* self, u32 mode, s32 mask) {
    u8* p;
    s32 id;
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    for (; i < self->count; off += 0x5C, i++) {
        p = self->data + off;
        if (p[0x99] == 0 && !((p[0xB5] >> 2) & 1) && !(mask & (1 << i))) {
            p[0xB5] |= 4;
            if (mode == 1) {
                id = getEntryId__9ftManagerFi(g_ftManager, i);
                if (id != -1) {
                    fn_27_10A274(g_ftManager, id, 1);
                    fn_27_10A320(g_ftManager, id, p[0xB6]);
                    fn_27_1F1B68(g_aiMgr, i, p[0xB7]);
                }
            } else {
                p[0x99] = 3;
            }
        }
    }
}
