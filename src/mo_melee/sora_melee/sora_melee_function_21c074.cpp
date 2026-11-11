#include <types.h>
#pragma force_active on

extern "C" void gfMemFill__FPvUcUl(void*, u8, u32);

struct Entry { char pad[4]; u8 id; char pad2[0x1f]; };
struct State { Entry entries[32]; };

extern "C" void fn_27_21C074(State* p) {
    gfMemFill__FPvUcUl(p, 0, 0x484);
    for (int i = 0; i < 32; i++) p->entries[i].id = i;
}