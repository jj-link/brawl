#include <types.h>
#pragma force_active on

struct BitField {
    s32 m0;
    s32 m4;
    s32 m8;
};

extern "C" s32 fn_27_CD258(BitField* f) {
    return f->m8 >> 28;
}
