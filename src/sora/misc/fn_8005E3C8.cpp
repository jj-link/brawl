#include <types.h>
#pragma force_active on
extern "C" const float lbl_805A1918;

struct Obj {
    u8 pad0[0xA4];
    u8 a4 : 8;
    u8 pad1[3];
    f32 a8;
    f32 ac;
    u8 b0, b1, b2, b3, b4, b5, b6, b7;
    u8 b8, b9, ba, bb;
};

extern "C" void fn_8005E3C8(char* arg0, u8* arg1, f32 farg0) {
    s8 idx = (s8)arg1[0];
    Obj* p = (Obj*)(arg0 + (idx << 5));
    p->a4 = 1;
    p->ac = lbl_805A1918;
    p->a8 = farg0;
    p->b0 = p->b8;
    p->b1 = p->b9;
    p->b2 = p->ba;
    p->b3 = p->bb;
    p->b4 = p->b8;
    p->b5 = p->b9;
    p->b6 = p->ba;
    p->b7 = 0;
}
