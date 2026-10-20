#include <types.h>
#pragma force_active on

struct BitField {
    u32 mPad0;
    u32 mPad4;
    u32 mFlags;
};

extern "C" u32 fn_27_1A7418(BitField* p) {
    return (p->mFlags >> 19) & 1;
}
