#include <types.h>
#pragma force_active on

struct Foo {
    u32 unk0;
    u32 unk4;
    s32 value;
};

extern "C" s32 fn_27_FF084(Foo* p) {
    return p->value >> 30;
}
