#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

struct Flags4924 {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 b7 : 1;
};

extern "C" {
void fn_80158BE0();
void fn_80159F04();

void fn_1_29FFC() {
    u8* obj = *(u8**)((u8*)g_GameGlobal + 0x30);
    Flags4924* f = (Flags4924*)(obj + 0x4924);
    f->b0 = 0;
    fn_80158BE0();
    fn_80159F04();
}
}
