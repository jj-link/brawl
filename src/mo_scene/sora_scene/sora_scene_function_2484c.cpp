#include <gf/gf_application.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_1_2484C(void* arg) {
    g_gfApplication->unkE8[0x28] = ((u8*)arg)[0x18];
}
