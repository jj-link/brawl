#include <types.h>
#include <gf/gf_application.h>
#pragma force_active on

extern "C" {
void fn_80016900(gfApplication* app, u32 flag, u32 value);
}

extern "C" bool fn_27_257598(u32 unused, u32 type, u32 value)
{
    if (type != 5) {
        return false;
    }
    fn_80016900(g_gfApplication, value != 0, 3);
    return true;
}
