#include <types.h>
#pragma force_active on

struct BF {
    u32 pad0;
    u32 pad1;
    u32 a : 6;
    u32 b : 3;
    u32 c : 23;
};

extern "C" {
void fn_27_CD06C(BF* p, u32 v) {
    p->b = v;
}
}
