#include <types.h>
#pragma force_active on

struct X {
    u32 pad0;
    u32 pad1;
    u32 a : 15;
    u32 b : 1;
    u32 c : 16;
};

extern "C" u32 fn_27_19B348(X* p) {
    return p->b;
}
