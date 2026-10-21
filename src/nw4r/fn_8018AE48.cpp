#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Obj {
    u8 _0[4];
    u32 p;
    u32 q;
    u32 r;
    u32 s;
    u16 lo;
    u16 hi;
    u32 t;
};

extern "C" void fn_801F3004(void *, const void *, u32, u16);

extern "C" void fn_8018AE48(Obj *out, Obj *obj) {
    fn_801F3004(obj, (const void *)out->p, (out->t >> 11) & 3, out->hi);
}
