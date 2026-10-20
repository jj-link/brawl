#include <types.h>
#pragma force_active on

struct S { u32 pad[2]; u32 hi : 4; u32 rest : 28; };

extern "C" void fn_27_1A73B8(S* s, u32 val) {
    s->hi = val;
}
