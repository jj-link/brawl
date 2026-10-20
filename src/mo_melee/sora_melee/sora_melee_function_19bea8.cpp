#include <types.h>
#pragma force_active on

typedef struct {
    u32 unk0;
    u32 unk4;
    u32 flagHi : 2;
    u32 flagRest : 30;
} FooObj;

namespace fn_27_19BEA8_ns {}

extern "C" void fn_27_19BEA8(FooObj* p, u32 v) {
    p->flagHi = v;
}
