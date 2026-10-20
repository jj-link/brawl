#include <gf/gf_application.h>
#pragma force_active on

extern "C" void fn_1_377BC(void* self) {
    g_gfApplication->unkD1[0x3F] = ((unsigned char*)self)[0x10];
}
