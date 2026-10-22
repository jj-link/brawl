#include <types.h>
#pragma force_active on

extern "C" void OSReport(const char*, ...);
extern "C" s32 fn_8004D148(void*);
extern "C" void fn_800B96E8(void*, u8);
extern "C" void* g_GameGlobal;
extern "C" char lbl_28_data_D4[];

struct Fn28Arg {
    s32 f00, f04, f08, f0c;
};

struct Fn28Self {
    u8 pad00[0x2c];
    u8 b0 : 6;
    u8 b6 : 1;
    u8 b7 : 1;
    u8 pad2d[0x11c - 0x2d];
    u32 f11c;
    u32 f120;
    u8 pad124[0x218 - 0x124];
    u32 f218;
    u8 pad21c[0x2d0 - 0x21c];
    u32 f2d0;
    u8 pad2d4[0x2e0 - 0x2d4];
    u32 f2e0;
    u8 pad2e4[0x338 - 0x2e4];
    u32 f338;
    u32 f33c;
    u8 pad340[0x34c - 0x340];
    s32 f34c;
};

extern "C" void fn_28_450(Fn28Self* self, const Fn28Arg& arg) {
    self->b6 = 0;
    self->f34c = arg.f0c;
    self->f120 = arg.f00;
    fn_800B96E8((u8*)self + 0x60, (u8)arg.f00);
    if (arg.f04 >= 0) {
        fn_800B96E8((u8*)self + 0x170, (u8)arg.f04);
    }
    if (arg.f08 >= 0) {
        fn_800B96E8((u8*)self + 0x228, (u8)arg.f08);
    }
    self->f218 = 0;
    self->f2d0 = 0;
    s32 r = fn_8004D148(g_GameGlobal);
    self->f11c = r;
    OSReport(lbl_28_data_D4, r);
    self->f338 = 0;
    self->f2e0 = 2;
    self->f33c = 0;
}
