#pragma force_active on
#include <types.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <ut/ut_nw.h>

extern "C" int fn_8008E3CC(void* a, u32* nodeIds, u32* count);

extern "C" void fn_8008E31C(void* a, nw4r::g3d::ScnMdl* mdl) {
    u32 x = *(u32*)((u8*)mdl + 0xE8);
    u32 nodeIds[200];
    int n = fn_8008E3CC(a, nodeIds, &x);
    if (n != 0) {
        nwSMSetNodeVisibility(mdl, n, nodeIds, false);
    }
}
