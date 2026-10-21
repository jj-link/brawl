#include <types.h>
#pragma force_active on

class MuMsg {
public:
    void beginPrint(u32 arg);
    char pad0[8];
    s32 unk8;
};

extern "C" void fn_80069EDC(s32, s32, s32);

extern "C" void fn_800B92D8(MuMsg* arg0, u32 arg1, s32 arg2, s32 arg3) {
    arg0->beginPrint(arg1);
    fn_80069EDC(arg0->unk8, arg2, arg3);
}
