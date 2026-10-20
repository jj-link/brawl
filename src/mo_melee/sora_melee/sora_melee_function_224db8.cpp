#include <types.h>
#pragma force_active on

struct sndSystem;
typedef s32 SndID;

extern sndSystem* g_sndSystem;

extern "C" s32 fn_800754E8(sndSystem*, SndID, s32, s32);
extern "C" void fn_8007798C(sndSystem*, s32, float);
extern "C" void fn_80075C8C(sndSystem*, s32, s32, s32);

extern "C" s32 fn_27_224DB8(SndID sndID, float pan) {
    s32 handle = fn_800754E8(g_sndSystem, sndID, -1, -1);
    if (handle == -1) {
        return -1;
    }

    fn_8007798C(g_sndSystem, handle, pan);
    fn_80075C8C(g_sndSystem, handle, 0, 0);
    return handle;
}
