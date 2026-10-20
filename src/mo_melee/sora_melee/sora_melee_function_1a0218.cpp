#include <types.h>
#pragma force_active on

struct fn27Bits {
    u32 pad0 : 3;
    u32 f : 3;
    u32 rest : 26;
};

extern "C" void fn_27_1A0218(void* self, u32 v) {
    fn27Bits* p = (fn27Bits*)((char*)self + 8);
    p->f = v;
}
