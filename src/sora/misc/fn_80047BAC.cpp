#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

extern "C" void fn_80047BAC(void* arg0, s8* arg1) {
    nw4r::g3d::ResMdl mdl(*(void**)((char*)arg0 + 0xE8));
    u32 count = mdl.GetResNodeNumEntries();
    for (u32 i = 0; i < count; ++i, ++arg1) {
        if (*arg1 == 0) {
            *arg1 = 3;
        }
    }
}
