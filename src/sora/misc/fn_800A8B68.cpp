#pragma force_active on
#include <types.h>

struct Obj {
    char pad[0x6C];
    float x, y, z;
    unsigned char flags;
};

struct Src {
    float x, y, z;
};

extern "C" void fn_800A8B68(char* base, s32 index, const Src* src) {
    Obj* p = (Obj*)(base + (index << 4));
    p->x = src->x;
    p->y = src->y;
    p->z = src->z;
    p->flags |= 0x80;
}
