#include <types.h>
#pragma force_active on

extern f32 lbl_805A3118;

struct Bits18 {
    u32 top : 9;
    u32 a : 3;
    u32 b : 3;
    u32 c : 6;
    u32 rest : 11;
};

struct Elem {
    u32 w0;
    u32 w4;
    u16 h8;
    u16 ha;
    f32 fc;
    f32 f10;
    u16 h14;
    u16 h16;
    Bits18 w18;
};

struct Obj {
    u8 pad[0x3C];
    u32 hi : 4;
    u32 rest : 28;
    Elem* f40;
};

extern "C" void fn_801899A4(Obj* arg0, s32 arg1) {
    if (arg1 != 0) {
        u32 r9 = arg0->hi;
        Elem* p = (Elem*)((u8*)arg0->f40 + r9 * 0x1C);
        f32 fv = lbl_805A3118;
        u32 i;
        for (i = r9; i < (u32)arg1; i++) {
            if (p != 0) {
                Bits18 t;
                p->w0 = 0;
                p->h8 = 0;
                p->ha = 0;
                t = p->w18;
                p->fc = fv;
                t.top = 0;
                t.a = 1;
                t.b = 1;
                t.c = 0;
                p->f10 = fv;
                p->h14 = 0;
                p->w4 = 0;
                p->w18 = t;
                p->h16 = 0;
            }
            p++;
        }
        arg0->hi = arg1;
    }
}
