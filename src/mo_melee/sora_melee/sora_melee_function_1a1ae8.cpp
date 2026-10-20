#include <types.h>
#pragma force_active on

struct BitField {
    u32 mPad0;
    u32 mPad4;
    u32 mFlags;

    u32 getFlag() {
        return (mFlags >> 13) & 1;
    }
};

extern "C" u32 fn_27_1A1AE8(BitField* p) {
    return (p->mFlags >> 13) & 1;
}
