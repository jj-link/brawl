#include <types.h>
#pragma force_active on

struct fn27LocalWork {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 e;
};

extern "C" s32 fn_27_319A8(void* self, void* p, void* loc, u32 a, u32 b, u32 c, u32 d, u32 e);

extern "C" bool fn_27_31DCC(u32* self, u32 p4, u32 p5, u32 p6, u32 p7) {
    fn27LocalWork loc;
    u32 e = loc.e;
    e = e & ~0x80;
    loc.a = 0;
    loc.b = 0;
    loc.c = 0;
    loc.d = 0;
    loc.e = e;
    self[2] = 0xFFFF;
    self[4] = 0xFFFF;
    return fn_27_319A8(self, &self[2], &loc, p4, p5, p6, p7, e) != 0;
}
