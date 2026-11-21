#include <types.h>
#pragma force_active on
struct Data { u8 a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aa,ab,ac; u16 h[9]; u8 b,c; u16 d; };
struct Dst { u8 p[0xfc9]; u8 f; u8 q[0x1024-0xfca]; Data data; };
extern "C" void fn_800CA988(Dst* d, Data* s) {
    d->data = *s;
    d->f |= 0x10;
}