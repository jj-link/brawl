#include <types.h>
#pragma force_active on

struct S_4B4 {
    u8 pad[0x4b4];
    u32 v;
};

struct Holder_0 {
    S_4B4* p;
};

extern "C" void fn_27_112238(Holder_0* h, u32 v) {
    h->p->v = v;
}
