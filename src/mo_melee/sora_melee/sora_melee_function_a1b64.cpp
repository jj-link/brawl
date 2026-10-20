#include <types.h>
#pragma force_active on

struct A1B64Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

extern "C" u32 fn_27_A1B64(const A1B64Obj *this_) {
    return (this_->unk8 >> 25) & 1;
}
