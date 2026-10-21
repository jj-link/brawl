#include <types.h>
#pragma force_active on

class Target {
public:
    virtual s16 m0();
    virtual s16 m1();
    virtual s16 m2();
    virtual s16 m3();
    virtual s16 m4();
    virtual s16 m5();
    virtual s16 m6();
    virtual s16 m7();
};

struct Container {
    u32 _0;
    u32 _4;
    Target target;
};

struct D8 {
    u8 _0[0x80];
    Container* self;
    u8 _84[0x3C];
    u32 c0;
};

struct O {
    u8 _0[0xD8];
    D8* d8;
};

struct L {
    u32 a;
    u32 b;
    u32* c;
    u32 d;
};

extern "C" {
extern u8 lbl_41_data_CE1C[0xC];
extern u8 lbl_41_data_3E50[0x40];
void fn_41_2D038(void*, s32, s16, void*, const void*);
}

extern "C" void* fn_41_3FF0C(void* self, O* o) {
    *(u32*)self = (u32)lbl_41_data_CE1C;
    u32 v = o->d8->c0;
    L loc;
    loc.a = 1;
    loc.b = 0x17;
    loc.c = &loc.a;
    loc.d = v;
    Container* cont = o->d8->self;
    s16 ret = cont->target.m7();
    fn_41_2D038((char*)self + 4, 1, ret, &loc.c, lbl_41_data_3E50);
    return self;
}
