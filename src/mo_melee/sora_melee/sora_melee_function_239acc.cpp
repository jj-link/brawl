#include <types.h>
#pragma force_active on

struct sndSystem;
extern sndSystem* g_sndSystem;
extern "C" void fn_8007798C(sndSystem*, s32, float);

extern "C" void fn_27_239ACC(s32 unused, s32 handle, float pan)
{
    if (handle == -1) {
        return;
    }
    fn_8007798C(g_sndSystem, handle, pan);
}
