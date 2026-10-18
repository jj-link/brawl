#include <types.h>
#pragma force_active on

struct Obj {
    virtual void f0();
    virtual void* f1(s32 idx);
};

struct Desc {
    u32 base;
    s32 count;
};

struct Src {
    u8 pad[4];
    s16 off;
};

extern "C" void fn_27_41678(void* p, u32 addr);

extern "C" void fn_27_41EFC(Src* src, Obj* obj, Desc* desc) {
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    for (; i < desc->count; off += 0x20, i++) {
        void* r = obj->f1(src->off + i);
        fn_27_41678(r, desc->base + off);
    }
}
