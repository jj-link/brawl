#include <types.h>
#pragma force_active on

extern "C" u64 fn_803F1798(u64, u32);

struct Elem {
    u8 pad[0x14d];
    u8 flag;
};

struct Check {
    u8 pad[0x2a];
    u8 flag;
};

struct Obj {
    u8 pad[0x150];
    u32 count;
    Elem** elems;
    Check* p158;
};

struct State {
    u32 unk0;
    u32 unk4;
    u64 bits;
};

extern "C" s32 fn_40_1CC10(Obj* obj, State* st) {
    st->unk0 = 0x30;
    st->bits = 0;
    if (obj->p158->flag == 1)
        return 0;
    u32 i = 0;
    while (i < obj->count) {
        if (obj->elems[i]->flag == 1) {
            u64 ret = fn_803F1798(1, i);
            st->bits |= ret;
        }
        i++;
    }
    return 1;
}