#include <types.h>
#pragma force_active on

extern "C" {
extern u8* g_GameGlobal;
extern const f32 lbl_27_rodata_3FB4;
extern const f32 lbl_27_rodata_3FB0;
void fn_27_242404(void* p);
void fn_27_247010(u8* self);
}

extern "C" void fn_27_247010(u8* self) {
    *(f32*)(*(u8**)(g_GameGlobal + 0x44) + 4) = lbl_27_rodata_3FB4;
    if (self[0x100] != 0) {
        self[0x40] = 3;
        return;
    }
    u8 flags = self[0x54];
    self[0x40] = 5;
    self[0x54] = flags | 0x80;
    *(f32*)(self + 0x4C) = lbl_27_rodata_3FB0;
    u8* gg = *(u8**)(g_GameGlobal + 0x30);
    if (((gg[0x4924] >> 6) & 1) == 0) {
        return;
    }
    void* p = *(void**)(self + 0x74);
    if (p != 0) {
        fn_27_242404(p);
        return;
    }
}
