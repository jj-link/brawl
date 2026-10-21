#include <types.h>
#pragma force_active on

struct Obj {
    virtual void f0();
    virtual void* f1(s32);
};

struct Src {
    u8 pad[4];
    s16 off;
};

struct Entry {
    float x0, x4, x8, xC, x10, x14, x18;
    s8 flag : 1;
    u32 kind;
    u32 id;
};

struct Desc {
    Entry* base;
    s32 count;
};

struct Temp {
    float x0, x4, x8, xC, x10, x14, x18;
    u32 id : 9;
    u32 zero0 : 2;
    u32 kind : 2;
    u32 zero1 : 2;
    u32 flag : 1;
    u32 rest : 16;
};

extern "C" void fn_27_41678(void*, const Temp*);

extern "C" void fn_27_41F7C(Src* src, Obj* obj, Desc* desc) {
    s32 off;
    s32 i;
    i = 0;
    off = 0;

    for (; i < desc->count; off += 0x28, i++) {
        Entry* in = (Entry*)((u8*)desc->base + off);
        Temp temp;
        temp.x0 = in->x0;
        temp.x4 = in->x4;
        temp.x8 = in->x8;
        temp.xC = in->xC;
        temp.x10 = in->x10;
        temp.x14 = in->x14;
        temp.x18 = in->x18;
        temp.id = in->id;
        temp.zero0 = 0;
        temp.kind = in->kind;
        temp.zero1 = 0;
        temp.flag = in->flag != 0;
        fn_27_41678(obj->f1(src->off + i), &temp);
    }
}
