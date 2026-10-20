#include <types.h>
#pragma force_active on

struct FnBits {
    u32 pad[2];
    u32 a : 3;
    u32 b : 3;
    u32 c : 26;
};

extern "C" void fn_27_CD008(FnBits* p, u32 v) {
    p->b = v;
}
