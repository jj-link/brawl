#include <types.h>
#pragma force_active on

struct FieldS {
    u32 pad[2];
    u32 a : 20;
    s32 b : 10;
    u32 c : 2;
};

extern "C" s32 fn_27_1A3F14(FieldS* p) {
    return p->b;
}
