#include <types.h>
#pragma force_active on

struct SomeObj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" u32 fn_27_1D0924(const SomeObj *obj) {
    return (obj->unk8 >> 19) & 1;
}
