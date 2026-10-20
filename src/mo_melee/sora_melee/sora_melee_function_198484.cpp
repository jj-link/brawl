#include <types.h>
#pragma force_active on

struct fn_27_198484_t {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" s32 fn_27_198484(const fn_27_198484_t* p) {
    return p->unk8 >> 29;
}
