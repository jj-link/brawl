#include <types.h>
#pragma force_active on

struct Something {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern "C" s32 fn_27_19CAE8(Something *p) {
    return p->unk8 >> 30;
}
