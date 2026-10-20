#include <types.h>
#pragma force_active on

struct FooChr {
    u32 m0;
    s16 m4;
    s16 pad6;
    u32 m8;
};

extern "C" {
void fn_27_376A58(FooChr* p) {
    if (p->m4 == -1) {
        return;
    }
    p->m4 = -1;
    if (p->m4 <= -1) {
        return;
    }
    p->m8 = 0;
}
}
