#include <types.h>

struct Slot {
    u32 unk0;
    u32 id;
    u32 unk8;
    u32 unkC;
    u8 flag;
    u8 pad[3];
};

#pragma force_active on
extern "C" int fn_8007AB34(Slot* base, u32 key) {
    u32 i;
    Slot* p = base;
    for (i = 0; i < 30; i++) {
        Slot* s = (i < 30) ? p : 0;
        if (s != 0 && s->flag != 0 && s->id == key)
            return 1;
        p++;
    }
    return 0;
}