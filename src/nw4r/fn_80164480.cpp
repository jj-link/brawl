#pragma force_active on
#include <types.h>
extern "C" {
s32 fn_8015C1B0(s32, s32);
s32 fn_80166E18(s32 a, s32 b, s32 c, s32 d, s32 e);

s32 fn_80164480(s32 self, s32 arg1, s32 arg2, s32 arg3) {
    s32 total = 0;
    s32 node = fn_8015C1B0(self + 0x24, 0);
    while (node != 0) {
        s32 next = fn_8015C1B0(self + 0x24, node);
        total += fn_80166E18(node, arg1, arg2, arg3, 0);
        node = next;
    }
    return total;
}
}
