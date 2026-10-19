#include <gf/gf_application.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" void fn_8004D010(void* game);

extern "C" void fn_1_36D98(void* self)
{
    *(int*)((char*)self + 0x8) = 0;
    *(int*)((char*)self + 0xC) = 0;
    *(unsigned char*)((char*)self + 0x10) =
        *((unsigned char*)g_gfApplication + 0x110) != 0;
    fn_8004D010(g_GameGlobal);
}
