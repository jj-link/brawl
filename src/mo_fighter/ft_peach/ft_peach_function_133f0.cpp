#include <types.h>
#pragma force_active on

extern "C" {
struct TripleStore {
    void* vtable;
    u32 pad;
    u32 f0;
    u32 f1;
    u32 f2;
};

void fn_103_133F0(TripleStore* p, u32 v) {
    p->f2 = v;
    p->f1 = v;
    p->f0 = v;
}
}
