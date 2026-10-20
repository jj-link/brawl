#include <types.h>
#pragma force_active on

struct BitField {
    u32 mPad0;
    u32 mPad4;
    u32 mFlags;

    s32 getKind() {
        return (s32)mFlags >> 28;
    }
};

extern "C" s32 fn_27_1A55F0(BitField* p) {
    return (s32)(p->mFlags) >> 28;
}
