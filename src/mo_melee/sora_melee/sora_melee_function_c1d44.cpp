#include <types.h>
#pragma force_active on

struct Pair {
    s32 a;
    s32 b;
};

struct Inner {
    u8 pad[0x20];
    Pair pr;
};

struct Obj {
    Inner* p0;
    u8 pad4[8];
    f32 fC;
    f32 f10;
    u8 pad14[4];
    u8 b18;
};

extern "C" void fn_27_C1B10(void* self, f32* a, Pair* b, Pair* c, s32 d, f32 e, f32 f);
extern "C" u32 fn_800110CC(void* a, void* b);
extern "C" const f32 lbl_27_rodata_EC0;

extern "C" void fn_27_C1D44(Obj* arg0, Obj* arg1, s32 arg2, u32 arg3) {
    f32 sp8;

    if (arg0->p0 != 0 && fn_800110CC(arg0->p0, arg1->p0) == 1) {
        u32 var31 = 0;
        u32 var6 = 0;
        if ((s8)arg0->b18 == (s8)arg1->b18) {
            var31 = 1;
            var6 = 1;
        } else {
            if ((s8)arg0->b18 > (s8)arg1->b18) {
                var31 = 1;
            }
            if ((s8)arg0->b18 <= (s8)arg1->b18) {
                var6 = 1;
            }
        }
        Pair sp18 = arg0->p0->pr;
        Pair sp10 = arg1->p0->pr;
        sp8 = lbl_27_rodata_EC0;
        if (var6 == 1) {
            fn_27_C1B10(arg0, &sp8, (Pair*)&sp18, (Pair*)&sp10, arg2, arg1->f10, arg1->fC);
        }
        if (arg3 == 1 && var31 == 1) {
            fn_27_C1B10(arg1, &sp8, (Pair*)&sp10, (Pair*)&sp18, arg2, arg0->f10, arg0->fC);
        }
    }
}
