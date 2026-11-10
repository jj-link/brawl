#include <types.h>
#pragma force_active on
struct Entry { u8 pad[0x24]; u32 a, b, c; };
extern "C" void fn_8032F714(Entry* p, s32 n) {
    for (s32 i = 0; i < n; ++i) {
        u32 value = p[i].b;
        p[i].c = value;
        p[i].a = value;
    }
}