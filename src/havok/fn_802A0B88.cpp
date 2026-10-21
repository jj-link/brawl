#include <revolution/OS/OSTime.h>
#include <types.h>
#pragma force_active on

extern "C" {

s64 fn_803F1470(s64 a, s64 b);
float fn_803F17E0(u64 val);
u64 fn_803F1960(float val);

extern f32 lbl_805A3EA8;

void fn_802A0B88(void) {
    s64 time = OSGetTime();
    u32 tick = *(u32*)0x800000F8;
    s64 div = (s64)(tick >> 2);
    s64 result = fn_803F1470(time, div);
    float d = fn_803F17E0((u64)result) + lbl_805A3EA8;
    fn_803F1960(d);
}

}
