#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct A {
    u8 pad[4];
    void* p;
};

struct D {
    u8 pad[6];
    u16 v;
};

extern "C" s32 fn_27_90D4(void* p, s32 b, u16 v);

extern "C" void fn_27_FF68(A* a, s32 b, s32 c, D* d) {
    s32 r = fn_27_90D4(a->p, b, d->v);
    if ((u32)(r + 0x10000) != 0xFFFF) {
        d->v = r;
    }
}
