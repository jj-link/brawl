#include <types.h>
#pragma force_active on

struct U { u32 a : 10; u32 f : 10; u32 b : 12; };
struct S { u32 pad0; u32 pad4; U u; };

extern "C" void fn_27_1A5A2C(S* s, u32 v) {
    s->u.f = v;
}
