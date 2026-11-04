#include <types.h>
#pragma force_active on

struct Elem12 {
    u32 a, b, c;
};

template <typename T> struct Unit {
    u8 flags;
    T element;
    s8 prev;
    s8 next;
};

struct ArrayList {
    u32 vtable;
    signed int freeIndex : 5;
    signed int topIndex : 5;
    signed int lastIndex : 5;
    signed int size : 5;
    Unit<Elem12> units[12];
};

extern "C" s32 fn_27_2BC3B0(void*, s32);
extern "C" s32 fn_27_2BC204(void*, s32);

extern "C" s32 fn_27_2BBB0C(ArrayList* self, s32 pos, s32 where) {
    s32 prev = -1;
    if (pos >= 0) {
        prev = fn_27_2BC3B0(self, pos);
        if (prev < 0) {
            return -1;
        }
    }
    s32 idx = fn_27_2BC204(self, where);
    if (idx < 0) {
        return -1;
    }
    s32 next = -1;
    if (prev < 0) {
        next = self->topIndex;
    } else if (self->units[prev].next >= 0) {
        next = self->units[prev].next;
    }
    if (prev >= 0) {
        self->units[prev].next = idx;
    } else {
        self->topIndex = idx;
    }
    self->units[idx].prev = prev;
    if (next >= 0) {
        self->units[next].prev = idx;
    } else {
        self->lastIndex = idx;
    }
    self->units[idx].next = next;
    self->units[idx].flags |= 0x80;
    return idx;
}
