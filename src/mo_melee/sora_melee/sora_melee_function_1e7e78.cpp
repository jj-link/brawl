#include <types.h>
#pragma force_active on

struct Foo {
    u32 unk0;
    u32 unk4;
    unsigned : 12;
    unsigned val : 1;
};

extern "C" s32 fn_27_1E7E78(const Foo* p) {
    return p->val;
}
