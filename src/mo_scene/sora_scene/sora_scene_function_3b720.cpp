#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_gfApplication;
extern void* g_GameGlobal;
void fn_8004D010(void* game);

void fn_1_3B720(void* self) {
    ((u32*)self)[2] = 0;
    ((u32*)self)[3] = 0;
    ((u8*)self)[16] = *((u8*)g_gfApplication + 0x110) != 0;
    fn_8004D010(g_GameGlobal);
}
}
